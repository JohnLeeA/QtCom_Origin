#ifndef USR_H
#define USR_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <qDebug>
#include <QString>
#include <windows.h>
#include <QTimer>
#include <qdatetime.h>
#include <QFile>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>
#include <QDir>

namespace Ui {
class usr;
}

class usr : public QDialog
{
    Q_OBJECT

public:
    explicit usr(QWidget *parent = 0);
    ~usr();

    int bytesToInt(QByteArray bytes);
    bool token = false;         //用于自动控制监测
    bool ifHandle = false;      //用于判断是否是手动监测

private slots:
    void on_send_clicked();
    void Read_Data();
    void on_openport_clicked();
    void on_startAutoControl_clicked();
    void sendchk();
    void on_autoControlSwitch_stateChanged(int arg1);
    void timerUpdate(void);
    QString getTime();
    void writeFile(QString str);
    void log(QString str);


    void on_write_clicked();

private:
    void timerEvent(QTimerEvent *);
    QSerialPort *serial;
    Ui::usr *ui;
    QByteArray requestData;//用于存储从串口那读取的数据
    QTimer *timer;//用于计时
};

#endif // USR_H
