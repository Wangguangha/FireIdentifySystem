/********************************************************************************
** Form generated from reading UI file 'Setting.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lab_IP;
    QLineEdit *lineEdit_IP;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *lab_Port;
    QLineEdit *lineEdit_Port;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lab_Frequency;
    QLineEdit *lineEdit_Frequency;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;

    void setupUi(QDialog *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(400, 281);
        verticalLayout = new QVBoxLayout(Setting);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lab_IP = new QLabel(Setting);
        lab_IP->setObjectName(QStringLiteral("lab_IP"));

        horizontalLayout->addWidget(lab_IP);

        lineEdit_IP = new QLineEdit(Setting);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));
        lineEdit_IP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_IP);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lab_Port = new QLabel(Setting);
        lab_Port->setObjectName(QStringLiteral("lab_Port"));

        horizontalLayout_2->addWidget(lab_Port);

        lineEdit_Port = new QLineEdit(Setting);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));
        lineEdit_Port->setEnabled(false);
        lineEdit_Port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit_Port);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lab_Frequency = new QLabel(Setting);
        lab_Frequency->setObjectName(QStringLiteral("lab_Frequency"));

        horizontalLayout_3->addWidget(lab_Frequency);

        lineEdit_Frequency = new QLineEdit(Setting);
        lineEdit_Frequency->setObjectName(QStringLiteral("lineEdit_Frequency"));
        lineEdit_Frequency->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lineEdit_Frequency);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(Setting);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QDialog *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Dialog", Q_NULLPTR));
        lab_IP->setText(QApplication::translate("Setting", "\345\256\242\346\210\267\347\253\257IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        lineEdit_IP->setText(QApplication::translate("Setting", "192.168.199.207", Q_NULLPTR));
        lab_Port->setText(QApplication::translate("Setting", "\345\256\242\346\210\267\347\253\257\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        lineEdit_Port->setText(QApplication::translate("Setting", "8888", Q_NULLPTR));
        lab_Frequency->setText(QApplication::translate("Setting", "\344\270\213\344\275\215\346\234\272\345\217\221\344\277\241\351\242\221\347\216\207(s)\357\274\232", Q_NULLPTR));
        lineEdit_Frequency->setText(QApplication::translate("Setting", "5", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Setting", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
