#ifndef FIREIDENTIFYSYSTEM_H
#define FIREIDENTIFYSYSTEM_H

#include <QSqlDatabase>
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

namespace Ui {
class FireIdentifySystem;
}

class FireIdentifySystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit FireIdentifySystem(QWidget *parent = 0);
    ~FireIdentifySystem();

    void InitWindow();                          //初始化窗体
    void showCharts();                          //展示折线图
    void openDataBase();                        //打开数据库
    void insertData(QString strData);           //数据库插入
    void startNetwork();                        //开启网络

private slots:
    void on_tBtn_Set_clicked();                 //系统设置槽函数
    void on_timer_timeout();                    //定时更新界面时间
    void on_updateTimer_timeout();              //定时更新界面图像
    void on_tBtn_LED_clicked();                 //LED按钮点击
    void on_tBtn_Buzzer_clicked();              //蜂鸣器按钮点击
    void on_tBtn_Network_clicked();             //网络按钮点击
    void on_tBtn_close_clicked();               //关闭按钮
    void serverNewConnect();                    //新的网络连接响应
    void serverReadData();                      //服务端读取数据
    void serverDisconnection();                 //服务端断开连接

private:
    Ui::FireIdentifySystem *ui;
    QTimer   *m_timer;                          //校准时间定时器
    QTimer   *m_UpdatePictrue;                  //更新图像定时器
    static bool LED_Switch;                     //LED开关
    static bool Buzzer_Switch;                  //蜂鸣器开关
    static bool Net_Switch;                     //网络开关
    static int Warn_Num;                        //警告数
    static int Error_Num;                       //警报数
    QSqlDatabase db;                            //数据库文件
    QTcpServer *tcpServer = new QTcpServer();   //Tcp服务端对象
    QTcpSocket *tcpSocket = new QTcpSocket();   //Tcp连接socket
    QByteArray array;                           //图像文件
};

#endif // FIREIDENTIFYSYSTEM_H
