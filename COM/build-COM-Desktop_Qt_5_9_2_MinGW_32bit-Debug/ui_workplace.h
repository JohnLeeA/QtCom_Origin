/********************************************************************************
** Form generated from reading UI file 'workplace.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKPLACE_H
#define UI_WORKPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_WorkPlace
{
public:
    QLabel *SelCom_Lab;
    QLabel *Bps_Lab;
    QLabel *Stop_Lab;
    QLabel *DataBit_Lab;
    QLabel *CheckBit_Lab;
    QComboBox *SelCom_Value;
    QComboBox *Bps_Value;
    QComboBox *Stop_Value;
    QComboBox *DataBit_Value;
    QComboBox *CheckBit_Value;
    QPushButton *CleanRevDate_Buttom;
    QPushButton *StartCom_Buttom;
    QTextEdit *SendShow_Text;
    QTextEdit *ReceiveShow_Text;
    QPushButton *SendOnce_Buttom;
    QPushButton *CleanSendDate_Buttom;

    void setupUi(QDialog *WorkPlace)
    {
        if (WorkPlace->objectName().isEmpty())
            WorkPlace->setObjectName(QStringLiteral("WorkPlace"));
        WorkPlace->resize(894, 356);
        SelCom_Lab = new QLabel(WorkPlace);
        SelCom_Lab->setObjectName(QStringLiteral("SelCom_Lab"));
        SelCom_Lab->setGeometry(QRect(20, 12, 51, 20));
        Bps_Lab = new QLabel(WorkPlace);
        Bps_Lab->setObjectName(QStringLiteral("Bps_Lab"));
        Bps_Lab->setGeometry(QRect(20, 52, 54, 20));
        Stop_Lab = new QLabel(WorkPlace);
        Stop_Lab->setObjectName(QStringLiteral("Stop_Lab"));
        Stop_Lab->setGeometry(QRect(20, 90, 54, 21));
        DataBit_Lab = new QLabel(WorkPlace);
        DataBit_Lab->setObjectName(QStringLiteral("DataBit_Lab"));
        DataBit_Lab->setGeometry(QRect(20, 130, 54, 21));
        CheckBit_Lab = new QLabel(WorkPlace);
        CheckBit_Lab->setObjectName(QStringLiteral("CheckBit_Lab"));
        CheckBit_Lab->setGeometry(QRect(20, 170, 54, 21));
        SelCom_Value = new QComboBox(WorkPlace);
        SelCom_Value->setObjectName(QStringLiteral("SelCom_Value"));
        SelCom_Value->setGeometry(QRect(70, 10, 73, 22));
        Bps_Value = new QComboBox(WorkPlace);
        Bps_Value->setObjectName(QStringLiteral("Bps_Value"));
        Bps_Value->setGeometry(QRect(70, 50, 73, 22));
        Stop_Value = new QComboBox(WorkPlace);
        Stop_Value->setObjectName(QStringLiteral("Stop_Value"));
        Stop_Value->setGeometry(QRect(70, 90, 73, 22));
        DataBit_Value = new QComboBox(WorkPlace);
        DataBit_Value->setObjectName(QStringLiteral("DataBit_Value"));
        DataBit_Value->setGeometry(QRect(70, 130, 73, 22));
        CheckBit_Value = new QComboBox(WorkPlace);
        CheckBit_Value->setObjectName(QStringLiteral("CheckBit_Value"));
        CheckBit_Value->setGeometry(QRect(70, 170, 73, 22));
        CleanRevDate_Buttom = new QPushButton(WorkPlace);
        CleanRevDate_Buttom->setObjectName(QStringLiteral("CleanRevDate_Buttom"));
        CleanRevDate_Buttom->setGeometry(QRect(130, 210, 93, 28));
        StartCom_Buttom = new QPushButton(WorkPlace);
        StartCom_Buttom->setObjectName(QStringLiteral("StartCom_Buttom"));
        StartCom_Buttom->setGeometry(QRect(20, 210, 93, 28));
        SendShow_Text = new QTextEdit(WorkPlace);
        SendShow_Text->setObjectName(QStringLiteral("SendShow_Text"));
        SendShow_Text->setGeometry(QRect(20, 250, 851, 81));
        ReceiveShow_Text = new QTextEdit(WorkPlace);
        ReceiveShow_Text->setObjectName(QStringLiteral("ReceiveShow_Text"));
        ReceiveShow_Text->setGeometry(QRect(160, 10, 711, 191));
        SendOnce_Buttom = new QPushButton(WorkPlace);
        SendOnce_Buttom->setObjectName(QStringLiteral("SendOnce_Buttom"));
        SendOnce_Buttom->setGeometry(QRect(780, 210, 93, 28));
        CleanSendDate_Buttom = new QPushButton(WorkPlace);
        CleanSendDate_Buttom->setObjectName(QStringLiteral("CleanSendDate_Buttom"));
        CleanSendDate_Buttom->setGeometry(QRect(670, 210, 93, 28));

        retranslateUi(WorkPlace);

        QMetaObject::connectSlotsByName(WorkPlace);
    } // setupUi

    void retranslateUi(QDialog *WorkPlace)
    {
        WorkPlace->setWindowTitle(QApplication::translate("WorkPlace", "Dialog", Q_NULLPTR));
        SelCom_Lab->setText(QApplication::translate("WorkPlace", "\344\270\262\345\217\243\351\200\211\346\213\251", Q_NULLPTR));
        Bps_Lab->setText(QApplication::translate("WorkPlace", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        Stop_Lab->setText(QApplication::translate("WorkPlace", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        DataBit_Lab->setText(QApplication::translate("WorkPlace", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        CheckBit_Lab->setText(QApplication::translate("WorkPlace", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        Bps_Value->clear();
        Bps_Value->insertItems(0, QStringList()
         << QApplication::translate("WorkPlace", "1200", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "4800", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "9600", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "115200", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "256000", Q_NULLPTR)
        );
        Stop_Value->clear();
        Stop_Value->insertItems(0, QStringList()
         << QApplication::translate("WorkPlace", "1", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "1.5", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "2", Q_NULLPTR)
        );
        DataBit_Value->clear();
        DataBit_Value->insertItems(0, QStringList()
         << QApplication::translate("WorkPlace", "5", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "6", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "7", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "8", Q_NULLPTR)
        );
        CheckBit_Value->clear();
        CheckBit_Value->insertItems(0, QStringList()
         << QApplication::translate("WorkPlace", "None", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "\345\201\266\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("WorkPlace", "\345\245\207\346\240\241\351\252\214", Q_NULLPTR)
        );
        CleanRevDate_Buttom->setText(QApplication::translate("WorkPlace", "\346\270\205\351\231\244\346\216\245\345\217\227", Q_NULLPTR));
        StartCom_Buttom->setText(QApplication::translate("WorkPlace", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        SendOnce_Buttom->setText(QApplication::translate("WorkPlace", "\345\217\221\351\200\201\344\270\200\346\254\241", Q_NULLPTR));
        CleanSendDate_Buttom->setText(QApplication::translate("WorkPlace", "\346\270\205\351\231\244\346\216\245\345\217\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WorkPlace: public Ui_WorkPlace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKPLACE_H
