#include "Setting.h"
#include "ui_Setting.h"

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_pushButton_clicked()
{
    //OK按钮槽函数
    this->IpAddr = ui->lineEdit_IP->text();
    this->Port = ui->lineEdit_Port->text();
    this->speed = ui->lineEdit_Frequency->text();
}
