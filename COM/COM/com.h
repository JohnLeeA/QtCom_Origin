#ifndef COM_H
#define COM_H

#include <QWidget>
#include "workplace.h"// 界面workplace

namespace Ui {
class COM;
}

class COM : public QWidget
{
    Q_OBJECT

public:
    explicit COM(QWidget *parent = 0);
    ~COM();

private slots:
    void on_Login_clicked();

private:
    Ui::COM *ui;
    WorkPlace *workPlace=new WorkPlace;

};

#endif // COM_H
