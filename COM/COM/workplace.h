#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <QDialog>
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息

namespace Ui {
class WorkPlace;
}

class WorkPlace : public QDialog
{
    Q_OBJECT

public:
    explicit WorkPlace(QWidget *parent =  nullptr);
    ~WorkPlace();

private slots:

    void on_StartCom_Buttom_clicked();

    void on_SendOnce_Buttom_clicked();

    void on_CleanRevDate_Buttom_clicked();

    void on_CleanSendDate_Buttom_clicked();

    void on_Search_Buttom_clicked();

    void on_Time_Button_clicked();

    void on_Open_Button_clicked();

    void Read_Data();

    void Analyze_Data();

private:
    Ui::WorkPlace *ui;
    QSerialPort *serial=new QSerialPort;
};

#endif // WORKPLACE_H
