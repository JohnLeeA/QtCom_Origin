/********************************************************************************
** Form generated from reading UI file 'com.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COM_H
#define UI_COM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_COM
{
public:
    QLineEdit *Name_Value;
    QLineEdit *Key_Value;
    QLabel *Name_Lab;
    QLabel *Key_Lab;
    QPushButton *Login;
    QPushButton *Cancle;

    void setupUi(QWidget *COM)
    {
        if (COM->objectName().isEmpty())
            COM->setObjectName(QStringLiteral("COM"));
        COM->resize(516, 476);
        Name_Value = new QLineEdit(COM);
        Name_Value->setObjectName(QStringLiteral("Name_Value"));
        Name_Value->setGeometry(QRect(200, 230, 113, 20));
        Key_Value = new QLineEdit(COM);
        Key_Value->setObjectName(QStringLiteral("Key_Value"));
        Key_Value->setGeometry(QRect(200, 270, 113, 20));
        Name_Lab = new QLabel(COM);
        Name_Lab->setObjectName(QStringLiteral("Name_Lab"));
        Name_Lab->setGeometry(QRect(170, 230, 31, 16));
        Key_Lab = new QLabel(COM);
        Key_Lab->setObjectName(QStringLiteral("Key_Lab"));
        Key_Lab->setGeometry(QRect(170, 270, 31, 16));
        Login = new QPushButton(COM);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(80, 370, 93, 28));
        Cancle = new QPushButton(COM);
        Cancle->setObjectName(QStringLiteral("Cancle"));
        Cancle->setGeometry(QRect(340, 370, 93, 28));

        retranslateUi(COM);
        QObject::connect(Cancle, SIGNAL(clicked()), COM, SLOT(close()));

        QMetaObject::connectSlotsByName(COM);
    } // setupUi

    void retranslateUi(QWidget *COM)
    {
        COM->setWindowTitle(QApplication::translate("COM", "COM", Q_NULLPTR));
        Name_Lab->setText(QApplication::translate("COM", "\350\264\246\345\217\267", Q_NULLPTR));
        Key_Lab->setText(QApplication::translate("COM", "\345\257\206\347\240\201", Q_NULLPTR));
        Login->setText(QApplication::translate("COM", "\347\231\273\345\275\225", Q_NULLPTR));
        Cancle->setText(QApplication::translate("COM", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class COM: public Ui_COM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COM_H
