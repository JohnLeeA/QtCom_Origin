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
    explicit WorkPlace(QWidget *parent = 0);
    ~WorkPlace();

private slots:
    void on_Bps_Value_activated(int index);

private:
    Ui::WorkPlace *ui;
};

#endif // WORKPLACE_H
