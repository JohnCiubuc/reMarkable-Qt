#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QString remarkDataDir = "/home/inathero/ReMarkable/home/root/";

    reMarkable = new RemarkableUserData(this);
    reMarkable->setHomeDir(remarkDataDir);
    reMarkable->startDebug();
}

MainWindow::~MainWindow()
{
    delete ui;
}

