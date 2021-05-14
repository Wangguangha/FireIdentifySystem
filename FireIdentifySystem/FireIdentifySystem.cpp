#include "Setting.h"
#include "FireIdentifySystem.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QBarSet>

QT_CHARTS_USE_NAMESPACE

#include "ui_FireIdentifySystem.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QWidget>
#include <QBuffer>
#include <QDebug>

//静态变量初始化
bool FireIdentifySystem::LED_Switch = false;
bool FireIdentifySystem::Buzzer_Switch = false;
bool FireIdentifySystem::Net_Switch = false;
int FireIdentifySystem::Warn_Num = 5;
int FireIdentifySystem::Error_Num = 6;

static QTextEdit *logTextEdit;              //log输出控件

FireIdentifySystem::FireIdentifySystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FireIdentifySystem)
{
    ui->setupUi(this);

    //在绑定回调函数之前，需要将控件初始化
    logTextEdit = new QTextEdit(this);
    logTextEdit->resize(1082,125);
    ui->verticalLayout_5->addWidget(logTextEdit,4);

    qInstallMessageHandler(logOutput);      //绑定回调函数
    InitWindow();
}

FireIdentifySystem::~FireIdentifySystem()
{
    delete ui;
}

void FireIdentifySystem::InitWindow()
{
    this->pictureName = "/home/wang/学习/毕设/Qt/images/background_title.png";

    timer_timeout();
    updateTimer_timeout();
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    m_timer->start(1000);             //每一秒更新一次时间

    m_UpdatePictrue = new QTimer(this);
    connect(m_UpdatePictrue, SIGNAL(timeout()), this, SLOT(updateTimer_timeout()));
    m_UpdatePictrue->start(30000);     //每30秒更新一次图像

    //建立tcp连接响应
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(serverNewConnect()));

    openDataBase();                   //打开数据库
    showCharts();                     //展示柱状图
    startNetwork();                   //开启tcp网络
}

void FireIdentifySystem::showCharts()
{
    //报警情况柱状图
    QBarSet *set0 = new QBarSet("警告");
    QBarSet *set1 = new QBarSet("报警");

    *set0 << 1 << 2 << 3 << 5 << 4;
    *set1 << 2 << 4 << 0 << 5 << 4;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("火情记录");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList dateList;
    dateList << "11" << "12" << "13" << "14" << "15";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(dateList);
    axisX->setTitleText("日期");

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,10);
    axisY->setLabelFormat("%d");
    axisY->setTickCount(6);
    axisY->setTitleText("次数");

    chart->setAxisX(axisX, series);                  //设置X坐标轴
    chart->setAxisY(axisY, series);                  //设置Y坐标轴

    chart->legend()->setVisible(true);              //设置图例为显示状态
    chart->legend()->setAlignment(Qt::AlignBottom); //设置图例的显示位置在底部

    ui->chart_Widget->setRenderHint(QPainter::Antialiasing);
    ui->chart_Widget->setChart(chart);
}

void FireIdentifySystem::timer_timeout()
{
    //定时更新时间timeout信号发送
    QDateTime curDateTime=QDateTime::currentDateTime();
    ui->dateTimeEdit->setDate(curDateTime.date());
    ui->dateTimeEdit->setTime(curDateTime.time());
}

void FireIdentifySystem::updateTimer_timeout()
{
    //定时更新图像timeout信号发送
    QPixmap *pixmap = new QPixmap(pictureName);
    pixmap->scaledToHeight(ui->lab_Picture->height());
    pixmap->scaled(ui->lab_Picture->size(), Qt::KeepAspectRatio);
    ui->lab_Picture->setScaledContents(true);
    ui->lab_Picture->setPixmap(*pixmap);

    ui->lab_Warning->setText(QString::number(Warn_Num));
    ui->lab_Error->setText(QString::number(Error_Num));
}

void FireIdentifySystem::on_tBtn_Set_clicked()
{
    //系统设置按钮槽函数
    Setting *set = new Setting();
    set->show();

    //初始化界面
    QImage img;
    img.load(":/images/background.png");
    ui->lab_Picture->setPixmap(QPixmap::fromImage(img.scaled(ui->lab_Picture->size())));
}

void FireIdentifySystem::sendSwitch(QString devSwitch)
{
    //发送数据到下位机
    qDebug() << devSwitch;
    tcpSocket->write(devSwitch.toLatin1().data());
    tcpSocket->flush();
}

void FireIdentifySystem::on_tBtn_LED_clicked()
{
    //LED按钮槽函数
    if(false == LED_Switch)
    {
        //如果开关为关
        ui->tBtn_LED->setIcon(QIcon(":/image/images/LED_ON.png"));
        ui->tBtn_LED->setStyleSheet("background-color:rgb(115, 210, 22)");
        sendSwitch("L1");
    }
    else
    {
        //如果开关为开
        ui->tBtn_LED->setIcon(QIcon(":/image/images/LED_OFF.png"));
        ui->tBtn_LED->setStyleSheet("background-color:rgb(204, 0, 0)");
        sendSwitch("L0");
    }
    LED_Switch = !LED_Switch;
}

void FireIdentifySystem::on_tBtn_Buzzer_clicked()
{
    //蜂鸣器按钮槽函数
    if(false == Buzzer_Switch)
    {
        //如果开关为关
        ui->tBtn_Buzzer->setStyleSheet("background-color:rgb(115, 210, 22)");
        sendSwitch("B1");
    }
    else
    {
        //如果开关为开
        ui->tBtn_Buzzer->setStyleSheet("background-color:rgb(204, 0, 0)");
        sendSwitch("B0");
    }
    Buzzer_Switch = !Buzzer_Switch;
}

void FireIdentifySystem::on_tBtn_Network_clicked()
{
    //网络按钮槽函数
//    if(false == Net_Switch)
//    {
//        //如果开关为关
//        ui->tBtn_Network->setStyleSheet("background-color:rgb(115, 210, 22)");
//    }else
//    {
//        //如果开关为开
//        ui->tBtn_Network->setStyleSheet("background-color:rgb(204, 0, 0)");
//    }
//    Net_Switch = !Net_Switch;
}

void FireIdentifySystem::openDataBase()
{
    //操作数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/wang/学习/毕设/Qt/dbFile/record.db");
    if (!db.open())
    {
        qDebug() << "数据库连接失败！";
    }else
    {
        qDebug() << "数据库打开成功!" << endl;
    }
}

void FireIdentifySystem::insertData(QString strList)
{
    //数据库插入
    QSqlQuery sqlQuery = QSqlQuery(db);
    if(!sqlQuery.exec(strList))
    {
        qDebug() << "数据库插入失败！";
    }
}

void FireIdentifySystem::startNetwork()
{
    //开启网络服务
    int port = 8888;                //Tcp端口号为8888
    if(!tcpServer->listen(QHostAddress::Any, port))
    {
        qDebug() << "服务器端监听失败！！！";
        return;
    }else
    {
        qDebug() << "服务器端监听成功！！！";
    }
}

void FireIdentifySystem::serverNewConnect()
{
    //服务端新连接槽函数
    tcpSocket = tcpServer->nextPendingConnection();
    if(!tcpSocket)
    {
        qDebug() << "未能成功获取客户端连接！！！";
    }else
    {
        qDebug() << "成功建立连接！！！";
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(serverReadData()));
        connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnection()));
    }
}

void FireIdentifySystem::serverReadData()
{
    //服务器接收图像函数
    QByteArray buf = tcpSocket->readAll();

    //判断发送的数据是否为文件名
    if(buf.contains("fileName:"))
    {
        this->array.clear();
        buf = buf.replace("fileName:","");
        QString fileName(buf);
        this->pictureName = fileName;
        qDebug() << "The fileName is:" + this->pictureName;
    }else if(buf.contains("fileLen:"))
    {
        buf = buf.replace("fileLen:","");
        QString str(buf);
        this->fileLen = buf.toInt();
        qDebug() << "The fileLen is:" << this->fileLen;
    }else
    {
        this->array.append(buf);

        if(this->array.size() >= this->fileLen)
        {
            QBuffer buffer(&this->array);
            buffer.open(QIODevice::ReadOnly);
            QPixmap picture;
            picture.loadFromData(this->array, "jpg");
            //将图像适应控件显示
            QPixmap pix = picture.scaledToHeight(ui->lab_Picture->height());
            ui->lab_Picture->setPixmap(pix);
            saveImage(pix);

            //火焰检测开关
            //Mat inputImg = imread("/home/wang/huo.jpeg",1);
            //CheckColor(inputImg);

            this->array.clear();
        }
    }
}

void FireIdentifySystem::serverDisconnection()
{
    //服务端断开连接
    qDebug() << "与客户端断开连接！！！";

    array.clear();
}

void FireIdentifySystem::saveImage(QPixmap pixmap)
{
    //保存图像到本地
    pixmap.save("./" + this->pictureName, "JPG");
}

void FireIdentifySystem::logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //日志重定向
    QString text;
    text.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " ");
    switch(type)
    {
        case QtDebugMsg:
            text.append("Debug：");
            break;

        case QtWarningMsg:
            text.append("Warning：");
            break;

        case QtCriticalMsg:
            text.append("Critical：");
            break;

        case QtFatalMsg:
            text.append("Fatal：");
    }
    text.append(msg);
    logTextEdit->append(text);
}

void FireIdentifySystem::on_pushButton_clicked()
{
    //清空Log槽函数
    logTextEdit->clear();
}

Mat FireIdentifySystem::CheckColor(Mat &inImg)
{
    Mat fireImg;
    fireImg.create(inImg.size(),CV_8UC1);

    int redThre = 115; // 115~135
    int saturationTh = 45; //55~65
    Mat multiRGB[3];
    int a = inImg.channels();
    split(inImg,multiRGB); //将图片拆分成R,G,B,三通道的颜色

    for (int i = 0; i < inImg.rows; i ++)
    {
        for (int j = 0; j < inImg.cols; j ++)
        {
            float B,G,R;
            B = multiRGB[0].at<uchar>(i,j); //每个像素的R,G,B值
            G = multiRGB[1].at<uchar>(i,j);
            R = multiRGB[2].at<uchar>(i,j);

            /*B = inImg.at<uchar>(i,inImg.channels()*j + 0); //另一种调用图片中像素RGB值的方法
            G = inImg.at<uchar>(i,inImg.channels()*j + 1);
            R = inImg.at<uchar>(i,inImg.channels()*j + 2);*/

            int maxValue = max(max(B,G),R);
            int minValue = min(min(B,G),R);

            double S = (1-3.0*minValue/(R+G+B));

            //R > RT  R>=G>=B  S>=((255-R)*ST/RT)
            if(R > redThre && R >= G && G >= B && S >0.20 && S >((255 - R) * saturationTh/redThre))
            {
                fireImg.at<uchar>(i,j) = 255;
            }
            else
            {
                fireImg.at<uchar>(i,j) = 0;
            }
        }
    }

    dilate(fireImg,fireImg,Mat(5,5,CV_8UC1));
    DrawFire(inImg,fireImg);

    return fireImg;
}

void FireIdentifySystem::LabelDisplayMat(QLabel *label, cv::Mat &mat)
{
    //将Mat显示到QLabel
    cv::Mat Rgb;
    QImage Img;
    if (mat.channels() == 3)//RGB Img
    {
        cv::cvtColor(mat, Rgb, CV_BGR2RGB);//颜色空间转换
        Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
    }
    else//Gray Img
    {
        Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
    }
    label->setPixmap(QPixmap::fromImage(Img));
}

void FireIdentifySystem::DrawFire(Mat &inputImg,Mat foreImg)
{
    vector<vector<Point>> contours_set;//保存轮廓提取后的点集及拓扑关系

    findContours(foreImg,contours_set,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);

    Mat result0;
    Scalar holeColor;
    Scalar externalColor;

    vector<vector<Point>>::iterator iter = contours_set.begin() ;
    for(; iter!= contours_set.end(); )
    {
        Rect rect = boundingRect((InputArray)(*iter));
        float radius;
        Point2f center;
        minEnclosingCircle((InputArray)(*iter),center,radius);

        if (rect.area()> 0)
        {
            if(rect.area() > 255)
            {
                //火焰区域大于255才视为真正发生火灾，提高准确率
                QSqlQuery query = QSqlQuery(db);

                query.exec("select count(*) from messagelist");
                query.next();
                listCount = query.value(0).toInt();

                QString strValue = QString("insert into messagelist values(%1,'%2',1,1)")
                        .arg(listCount+3)
                        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                qDebug() << strValue;
                query.exec(strValue);
                sendSwitch("B1");
                sendSwitch("L1");
            }
            rectangle(inputImg,rect,Scalar(0,255,0));
            ++ iter;
        }
        else
        {
            iter = contours_set.erase(iter);
        }
    }

    LabelDisplayMat(ui->lab_Picture, inputImg);
    waitKey(1000);
}
