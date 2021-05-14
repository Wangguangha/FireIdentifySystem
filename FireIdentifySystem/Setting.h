#ifndef SETTING_H
#define SETTING_H

#include <QDialog>

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

    QString IpAddr;         //IP地址
    QString Port;           //端口号
    QString speed;          //通信频率

private slots:
    void on_pushButton_clicked();

private:
    Ui::Setting *ui;
};

#endif // SETTING_H
