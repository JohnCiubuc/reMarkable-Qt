/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_ImportNewFile;
    QPushButton *pushButton_DeleteFile;
    QFrame *line;
    QPushButton *pushButton_Refresh;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Sync;
    QPushButton *pushButton_Reboot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setIconSize(QSize(100, 100));
        listWidget->setViewMode(QListView::IconMode);

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_ImportNewFile = new QPushButton(groupBox);
        pushButton_ImportNewFile->setObjectName(QString::fromUtf8("pushButton_ImportNewFile"));
        pushButton_ImportNewFile->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(pushButton_ImportNewFile);

        pushButton_DeleteFile = new QPushButton(groupBox);
        pushButton_DeleteFile->setObjectName(QString::fromUtf8("pushButton_DeleteFile"));
        pushButton_DeleteFile->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(pushButton_DeleteFile);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        pushButton_Refresh = new QPushButton(groupBox);
        pushButton_Refresh->setObjectName(QString::fromUtf8("pushButton_Refresh"));
        pushButton_Refresh->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(pushButton_Refresh);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_Sync = new QPushButton(groupBox);
        pushButton_Sync->setObjectName(QString::fromUtf8("pushButton_Sync"));
        pushButton_Sync->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(pushButton_Sync);

        pushButton_Reboot = new QPushButton(groupBox);
        pushButton_Reboot->setObjectName(QString::fromUtf8("pushButton_Reboot"));
        pushButton_Reboot->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(pushButton_Reboot);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        pushButton_ImportNewFile->setText(QCoreApplication::translate("MainWindow", "Import New File", nullptr));
        pushButton_DeleteFile->setText(QCoreApplication::translate("MainWindow", "Delete File", nullptr));
        pushButton_Refresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        pushButton_Sync->setText(QCoreApplication::translate("MainWindow", "Sync", nullptr));
        pushButton_Reboot->setText(QCoreApplication::translate("MainWindow", "Reboot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
