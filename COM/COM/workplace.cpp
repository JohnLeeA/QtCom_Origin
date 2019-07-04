#include "workplace.h"
#include "ui_workplace.h"
#include "QMessageBox"
#include "QTime"
#include "QTextCodec"
#include "QDebug"
/*
 * 构造函数
 * 初始化界面基本设置
 */
WorkPlace::WorkPlace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkPlace)
{
    ui->setupUi(this);
    ui->SendOnce_Buttom->setEnabled(false);
    ui->Bps_Value->setCurrentIndex(3);
    ui->Stop_Value->setCurrentIndex(0);
    ui->DataBit_Value->setCurrentIndex(3);
    ui->CheckBit_Value->setCurrentIndex(0);
    ui->Open_Button->setEnabled(false);
    ui->Time_Button->setEnabled(false);

    // 初始化检测所有串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        serial->setPort(info);
        if(serial->open(QIODevice::ReadWrite))
        {
            ui->SelCom_Value->addItem(serial->portName());
            serial->close();
        }
    }
}

/*
 * 析构函数
 */
WorkPlace::~WorkPlace()
{
    delete ui;
}

/*
 * 点击开始检测按键
 */
void WorkPlace::on_StartCom_Buttom_clicked()
{
    if(ui->StartCom_Buttom->text() == QString("打开串口")){// 关闭状态>>>>打开
        // 串口号
        serial->setPortName(ui->SelCom_Value->currentText());
        // 波特率
        serial->setBaudRate(ui->Bps_Value->currentText().toInt());
        //QMessageBox::about(NULL, "Bps", QString::number(ui->Bps_Value->currentText().toInt()));
        // 数据位设置
        switch(ui->DataBit_Value->currentIndex()){
            case 3: serial->setDataBits(QSerialPort::Data8); break;// QMessageBox::about(NULL, "数据", "8");
            case 2: serial->setDataBits(QSerialPort::Data7); break;
            case 1: serial->setDataBits(QSerialPort::Data6); break;
            case 0: serial->setDataBits(QSerialPort::Data5); break;
            default: break;
        }
        // 设置校验
        switch(ui->CheckBit_Value->currentIndex()){
            case 0:serial->setParity(QSerialPort::NoParity);break;// QMessageBox::about(NULL, "校验", "0");
            case 1:serial->setParity(QSerialPort::OddParity);break;
            case 2:serial->setParity(QSerialPort::EvenParity);break;
            default:break;
        }
        // 设置停止位
        switch(ui->Stop_Value->currentIndex()){
            case 0: serial->setStopBits(QSerialPort::OneStop); break;// QMessageBox::about(NULL, "停止", "1");
            case 1: serial->setStopBits(QSerialPort::TwoStop); break;
            default: break;
        }
        // 设置数据流控制位
        serial->setFlowControl(QSerialPort::NoFlowControl);

        // 检测串口是否被成功打开
        if(!serial->open(QIODevice::ReadWrite)){
            // ui->StartCom_Buttom->text() = QString("关闭串口");
            QMessageBox::about(nullptr, "提示", "无法打开串口！");
            return;
        }else{
            // 关闭下拉
            ui->SelCom_Value->setEnabled(false);
            ui->Bps_Value->setEnabled(false);
            ui->CheckBit_Value->setEnabled(false);
            ui->DataBit_Value->setEnabled(false);
            ui->Stop_Value->setEnabled(false);

            // 发送按钮打开
            ui->SendOnce_Buttom->setEnabled(true);
            ui->StartCom_Buttom->setText(QString("关闭串口"));

            // 将显示信号绑定到显示窗口
            if(ui->Open_Button->text() == QString("开始解析")){// 未解析状态
                QObject::connect(serial,&QSerialPort::readyRead,this,&WorkPlace::Read_Data);
            }else{                                            // 正在解析
                QObject::connect(serial,&QSerialPort::readyRead,this,&WorkPlace::Analyze_Data);
            }
            // QObject::connect(serial,&QSerialPort::readyRead,this,&WorkPlace::Read_Data);
            // 允许点击解析按钮
            ui->Open_Button->setEnabled(true);
        }
    }else{// 打开状态>>>>关闭
        serial->close();
        //下拉菜单控件使能
        ui->SelCom_Value->setEnabled(true);
        ui->Bps_Value->setEnabled(true);
        ui->CheckBit_Value->setEnabled(true);
        ui->DataBit_Value->setEnabled(true);
        ui->Stop_Value->setEnabled(true);

        ui->StartCom_Buttom->setText(QString("打开串口"));
        ui->SendOnce_Buttom->setEnabled(false);
        ui->Open_Button->setText(QString("开始解析"));
        ui->Time_Button->setText(QString("打开时间戳"));
        ui->Open_Button->setEnabled(false);
        ui->Time_Button->setEnabled(false);

        //关闭显示绑定
        if(ui->Open_Button->text() == QString("开始解析")){
            QObject::disconnect(serial,&QSerialPort::readyRead,this,&WorkPlace::Read_Data);
        }else{
            QObject::disconnect(serial,&QSerialPort::readyRead,this,&WorkPlace::Analyze_Data);
        }
    }
}
/*
 * 1，读取外部串口中数据
 * 2，将数据发送到接受窗口
 * 可能扫描执行
 */
void WorkPlace::Read_Data()
{
    QByteArray buf;
    buf = serial->readAll();
    if(!buf.isEmpty())
    {
        QString str = nullptr;
        str=tr(buf);
        // ui->ReceiveShow_Text->textCursor().atEnd();
        // ui->ReceiveShow_Text->textCursor().deleteChar();
        ui->ReceiveShow_Text->append(str);
        // ui->ReceiveShow_Text->moveCursor(QTextCursor::End);

    }
    buf.clear();
}

/*
 * 发送一次数据
 * 点击事件触发
 */
void WorkPlace::on_SendOnce_Buttom_clicked()
{
    serial->write(ui->SendShow_Text->toPlainText().toLatin1());
}

/*
 * 清除接受窗口按键
 * 点击事件触发
 */
void WorkPlace::on_CleanRevDate_Buttom_clicked()
{
    ui->ReceiveShow_Text->clear();
}

/*
 * 清除发送窗口按键
 * 点击事件触发
 */
void WorkPlace::on_CleanSendDate_Buttom_clicked()
{
    ui->SendShow_Text->clear();
}

void WorkPlace::on_Search_Buttom_clicked()
{
    if(ui->StartCom_Buttom->text() == QString("打开串口")){// 关闭状态
        ui->SelCom_Value->clear();
        foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            serial->setPort(info);
            if(serial->open(QIODevice::ReadWrite))
            {
                ui->SelCom_Value->addItem(serial->portName());
                serial->close();
            }
        }
    }
}
/*
 * 时间戳控制按键
 */
void WorkPlace::on_Time_Button_clicked()
{
    if(ui->Time_Button->text() == QString("打开时间戳")){
        ui->Time_Button->setText(QString("关闭时间戳"));
    }else{
        ui->Time_Button->setText(QString("打开时间戳"));
    }
}

/*
 * 开始解析按键
 */
void WorkPlace::on_Open_Button_clicked()
{
    if(ui->Open_Button->text() == QString("开始解析")){ // 进入解析状态
        ui->Open_Button->setText(QString("停止解析"));
        QObject::disconnect(serial,&QSerialPort::readyRead,this,&WorkPlace::Read_Data);
        QObject::connect(serial,&QSerialPort::readyRead,this,&WorkPlace::Analyze_Data);
        ui->Time_Button->setEnabled(true);
    }else{                                             // 退出解析状态
        ui->Open_Button->setText(QString("开始解析"));
        QObject::disconnect(serial,&QSerialPort::readyRead,this,&WorkPlace::Analyze_Data);
        QObject::connect(serial,&QSerialPort::readyRead,this,&WorkPlace::Read_Data);
        ui->Time_Button->setText(QString("打开时间戳"));
        ui->Time_Button->setEnabled(false);
    }
}

void WorkPlace::Analyze_Data()
{
    QByteArray buf;
    buf = serial->readAll();
//    QDataStream buf_Str(&buf,QIODevice::ReadWrite);

//    // qDebug()<<buf_Str;
//    while(!buf_Str.atEnd())
//    {
//        qint8 outChar = 0;
//        out>>outChar;   //每字节填充一次，直到结束
//        //十六进制的转换
//        QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));
//    }
    QString buf_Str = QString(buf);
    if(!buf.isEmpty())
    {
        QString str = nullptr;
        if(ui->Time_Button->text() == QString("关闭时间戳")){ // 处于开启状态
            QString time = QDateTime::currentDateTime().toString(Qt::ISODate);
            str = time + QString(" : ") + buf_Str;//+ QString("\n");
        }else{
            QString time = QDateTime::currentDateTime().toString(Qt::ISODate);
            str = buf_Str;
        }
        ui->ReceiveShow_Text->append(str);
    }
    buf.clear();
}
