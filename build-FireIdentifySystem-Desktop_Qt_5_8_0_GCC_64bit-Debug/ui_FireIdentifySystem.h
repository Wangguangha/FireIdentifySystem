/********************************************************************************
** Form generated from reading UI file 'FireIdentifySystem.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIREIDENTIFYSYSTEM_H
#define UI_FIREIDENTIFYSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_FireIdentifySystem
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QWidget *gBox_status;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lab_Picture;
    QWidget *gBox_result;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_Error;
    QLabel *lab_Warning;
    QChartView *chart_Widget;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *tBtn_LED;
    QSpacerItem *horizontalSpacer;
    QToolButton *tBtn_Buzzer;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tBtn_Network;
    QSpacerItem *horizontalSpacer_3;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *tBtn_Set;

    void setupUi(QMainWindow *FireIdentifySystem)
    {
        if (FireIdentifySystem->objectName().isEmpty())
            FireIdentifySystem->setObjectName(QStringLiteral("FireIdentifySystem"));
        FireIdentifySystem->resize(941, 530);
        FireIdentifySystem->setStyleSheet(QStringLiteral("background-color:rgb(114, 159, 207);"));
        centralWidget = new QWidget(FireIdentifySystem);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, -1, 3, -1);
        gBox_status = new QWidget(centralWidget);
        gBox_status->setObjectName(QStringLiteral("gBox_status"));
        verticalLayout_2 = new QVBoxLayout(gBox_status);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lab_Picture = new QLabel(gBox_status);
        lab_Picture->setObjectName(QStringLiteral("lab_Picture"));
        lab_Picture->setMinimumSize(QSize(0, 0));
        lab_Picture->setMaximumSize(QSize(16777215, 16777215));
        lab_Picture->setLayoutDirection(Qt::LeftToRight);
        lab_Picture->setStyleSheet(QLatin1String("background-color:rgb(138, 226, 52);\n"
"border-radius: 15px"));
        lab_Picture->setScaledContents(false);

        verticalLayout->addWidget(lab_Picture);

        verticalLayout->setStretch(0, 9);

        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(gBox_status);

        gBox_result = new QWidget(centralWidget);
        gBox_result->setObjectName(QStringLiteral("gBox_result"));
        verticalLayout_4 = new QVBoxLayout(gBox_result);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lab_Error = new QLabel(gBox_result);
        lab_Error->setObjectName(QStringLiteral("lab_Error"));
        QFont font;
        font.setPointSize(50);
        lab_Error->setFont(font);
        lab_Error->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color:red"));
        lab_Error->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lab_Error);

        lab_Warning = new QLabel(gBox_result);
        lab_Warning->setObjectName(QStringLiteral("lab_Warning"));
        lab_Warning->setFont(font);
        lab_Warning->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color:rgb(252, 233, 79)"));
        lab_Warning->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lab_Warning);


        verticalLayout_3->addLayout(horizontalLayout_2);

        chart_Widget = new QChartView(gBox_result);
        chart_Widget->setObjectName(QStringLiteral("chart_Widget"));
        chart_Widget->setStyleSheet(QStringLiteral("background-color:rgb(136, 138, 133)"));

        verticalLayout_3->addWidget(chart_Widget);

        verticalLayout_3->setStretch(0, 4);
        verticalLayout_3->setStretch(1, 14);

        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addWidget(gBox_result);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tBtn_LED = new QToolButton(centralWidget);
        tBtn_LED->setObjectName(QStringLiteral("tBtn_LED"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/images/LED_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtn_LED->setIcon(icon);
        tBtn_LED->setIconSize(QSize(20, 20));
        tBtn_LED->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(tBtn_LED);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        tBtn_Buzzer = new QToolButton(centralWidget);
        tBtn_Buzzer->setObjectName(QStringLiteral("tBtn_Buzzer"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/images/Buzzer.png"), QSize(), QIcon::Selected, QIcon::On);
        tBtn_Buzzer->setIcon(icon1);
        tBtn_Buzzer->setIconSize(QSize(20, 20));
        tBtn_Buzzer->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(tBtn_Buzzer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        tBtn_Network = new QToolButton(centralWidget);
        tBtn_Network->setObjectName(QStringLiteral("tBtn_Network"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/images/Wifi.png"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QStringLiteral(":/image/images/Wifi.png"), QSize(), QIcon::Selected, QIcon::On);
        tBtn_Network->setIcon(icon2);
        tBtn_Network->setIconSize(QSize(20, 20));
        tBtn_Network->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(tBtn_Network);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setEnabled(true);
        dateTimeEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(dateTimeEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, 9, -1);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        tBtn_Set = new QToolButton(centralWidget);
        tBtn_Set->setObjectName(QStringLiteral("tBtn_Set"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/images/Set.png"), QSize(), QIcon::Selected, QIcon::On);
        tBtn_Set->setIcon(icon3);
        tBtn_Set->setIconSize(QSize(20, 20));
        tBtn_Set->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_5->addWidget(tBtn_Set);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 1);

        horizontalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 2);
        horizontalLayout_3->setStretch(5, 1);
        horizontalLayout_3->setStretch(6, 4);
        horizontalLayout_3->setStretch(7, 2);
        horizontalLayout_3->setStretch(8, 2);
        horizontalLayout_3->setStretch(9, 8);

        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_5->setStretch(0, 9);
        verticalLayout_5->setStretch(1, 1);

        verticalLayout_6->addLayout(verticalLayout_5);

        FireIdentifySystem->setCentralWidget(centralWidget);

        retranslateUi(FireIdentifySystem);

        QMetaObject::connectSlotsByName(FireIdentifySystem);
    } // setupUi

    void retranslateUi(QMainWindow *FireIdentifySystem)
    {
        FireIdentifySystem->setWindowTitle(QApplication::translate("FireIdentifySystem", "FireIdentifySystem", Q_NULLPTR));
        lab_Picture->setText(QString());
        lab_Error->setText(QString());
        lab_Warning->setText(QString());
        tBtn_LED->setText(QApplication::translate("FireIdentifySystem", "LED", Q_NULLPTR));
        tBtn_Buzzer->setText(QApplication::translate("FireIdentifySystem", "\350\234\202\351\270\243\345\231\250", Q_NULLPTR));
        tBtn_Network->setText(QApplication::translate("FireIdentifySystem", "\347\275\221\347\273\234", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FireIdentifySystem", "\346\270\205\347\251\272Log", Q_NULLPTR));
        tBtn_Set->setText(QApplication::translate("FireIdentifySystem", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FireIdentifySystem: public Ui_FireIdentifySystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIREIDENTIFYSYSTEM_H
