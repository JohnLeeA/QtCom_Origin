#include "workplace.h"
#include "ui_workplace.h"
/*
 * 构造函数
 * 初始化界面基本设置
 */
WorkPlace::WorkPlace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkPlace)
{
    ui->setupUi(this);
    ui->Bps_Value->setCurrentIndex(3);
    ui->Stop_Value->setCurrentIndex(0);
    ui->DataBit_Value->setCurrentIndex(3);
    ui->CheckBit_Value->setCurrentIndex(0);
}

/*
 * 析构函数
 */
WorkPlace::~WorkPlace()
{
    delete ui;
}

/*
 * 波特率设置事件
 */
void WorkPlace::on_Bps_Value_activated(int index)
{
    ;
}
