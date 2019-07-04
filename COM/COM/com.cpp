#include "com.h"
#include "ui_com.h"
#include "QMessageBox"

COM::COM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::COM)
{
    ui->setupUi(this);
    ui->Key_Value->setEchoMode(QLineEdit::Password);//当输入密码时，显示为圆点
}

COM::~COM()
{
    delete ui;
}

void COM::on_Login_clicked()
{
    //去除lineEdit内的用户名和密码进行校验
//    if(this->ui->Name_Value->text().trimmed() == tr("admin") && this->ui->Key_Value->text().trimmed()== tr("root"))
//    {
//         //登陆成功后显示对话框
//         this->hide();
//         workPlace->show();
//    }
//    else
//    {
//        //用户输入存在错误
//        QMessageBox::warning(this,tr("waring"),tr("your passward is wrong"),QMessageBox::Yes);
//        ui->Name_Value->clear();  //清空姓名usrname
//        ui->Key_Value->clear();  //清空密码passward
//        ui->Name_Value->setFocus();  //将鼠标重新定位到usrname
//    }
    this->hide();
    workPlace->show();

}
