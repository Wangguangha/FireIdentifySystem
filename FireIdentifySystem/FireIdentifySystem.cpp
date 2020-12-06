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
#include <QDebug>

//静态变量初始化
bool FireIdentifySystem::LED_Switch = false;
bool FireIdentifySystem::Buzzer_Switch = false;
bool FireIdentifySystem::Net_Switch = false;
int FireIdentifySystem::Warn_Num = 5;
int FireIdentifySystem::Error_Num = 5;

FireIdentifySystem::FireIdentifySystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FireIdentifySystem)
{
    ui->setupUi(this);
    InitWindow();
}

FireIdentifySystem::~FireIdentifySystem()
{
    delete ui;
}

void FireIdentifySystem::InitWindow()
{
    //初始化界面
    on_timer_timeout();
    on_updateTimer_timeout();
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
    m_timer->start(1000);             //每一秒更新一次时间

    m_UpdatePictrue = new QTimer(this);
    connect(m_UpdatePictrue, SIGNAL(timeout()), this, SLOT(on_updateTimer_timeout()));
    m_UpdatePictrue->start(5000);     //每五秒更新一次图像


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

void FireIdentifySystem::on_timer_timeout()
{
    //定时更新时间timeout信号发送
    QDateTime curDateTime=QDateTime::currentDateTime();
    ui->dateTimeEdit->setDate(curDateTime.date());
    ui->dateTimeEdit->setTime(curDateTime.time());
}

void FireIdentifySystem::on_updateTimer_timeout()
{
    //定时更新图像timeout信号发送
    QPixmap *pixmap = new QPixmap(":/image/images/background.jpeg");
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
}

void FireIdentifySystem::on_tBtn_LED_clicked()
{
    //LED按钮槽函数
    if(false == LED_Switch)
    {
        //如果开关为关
        ui->tBtn_LED->setIcon(QIcon(":/image/images/LED_ON.png"));
        ui->tBtn_LED->setStyleSheet("background-color:rgb(115, 210, 22)");
    }else
    {
        //如果开关为开
        ui->tBtn_LED->setIcon(QIcon(":/image/images/LED_OFF.png"));
        ui->tBtn_LED->setStyleSheet("background-color:rgb(204, 0, 0)");
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
    }else
    {
        //如果开关为开
        ui->tBtn_Buzzer->setStyleSheet("background-color:rgb(204, 0, 0)");
    }
    Buzzer_Switch = !Buzzer_Switch;
}

void FireIdentifySystem::on_tBtn_Network_clicked()
{
    //网络按钮槽函数
    if(false == Net_Switch)
    {
        //如果开关为关
        ui->tBtn_Network->setStyleSheet("background-color:rgb(115, 210, 22)");
    }else
    {
        //如果开关为开
        ui->tBtn_Network->setStyleSheet("background-color:rgb(204, 0, 0)");
    }
    Net_Switch = !Net_Switch;
}

void FireIdentifySystem::on_tBtn_close_clicked()
{
    //关闭按钮槽函数
    this->close();
}

void FireIdentifySystem::openDataBase()
{
    //操作数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/wang/学习/毕设/Qt/dbFile/record.db");
    if (!db.open())
    {
        QMessageBox::critical(NULL, QObject::tr("Collection"), QObject::tr("数据库连接失败！"));
    }

    //insertData("insert into messagelist values(1,'2016-01-22 08:45:50',1,1)");
}

void FireIdentifySystem::insertData(QString strList)
{
    //数据库插入
    QSqlQuery sqlQuery = QSqlQuery(db);

    if(!sqlQuery.exec(strList))
    {
        QMessageBox::critical(NULL, QObject::tr("Collection"), QObject::tr("数据库插入失败！"));
    }
}

void FireIdentifySystem::startNetwork()
{
    //开启网络服务
    int port = 8888;                //Tcp端口号为8888
    if(!tcpServer->listen(QHostAddress::Any, port))
    {
        //QMessageBox::information(this, "QT网络故障", "服务器端监听失败！！！");
        qDebug() << "服务器端监听失败！！！";
        return;
    }else
    {
        //QMessageBox::information(this, "QT网络通信", "服务器端监听成功！！！");
        qDebug() << "服务器端监听成功！！！";
    }
}

void FireIdentifySystem::serverNewConnect()
{
    //服务端新连接槽函数
    tcpSocket = tcpServer->nextPendingConnection();
    if(!tcpSocket)
    {
        //QMessageBox::information(this, "QT网络通信", "未能成功获取客户端连接！！！");
        qDebug() << "未能成功获取客户端连接！！！";
    }else
    {
        //QMessageBox::information(this, "QT网络通信", "成功建立连接！！！");
        qDebug() << "成功建立连接！！！";
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(serverReadData()));
        connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnection()));
    }
}

void FireIdentifySystem::serverReadData()
{
    //服务器数据读取函数
    char buffer[1024];
    tcpSocket->read(buffer, 1024);
    qDebug() << buffer;
}

void FireIdentifySystem::serverDisconnection()
{
    //服务端断开连接
    //QMessageBox::information(this, "QT网络通信", "与客户端断开连接！！！");
    qDebug() << "与客户端断开连接！！！";
    return;
}