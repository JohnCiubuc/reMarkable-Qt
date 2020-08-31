#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include "utilities.h"
#include "remarkableuserdata.h"
#include "remarkablessh.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void remarkableReady();

    void on_pushButton_ImportNewFile_clicked();

    void on_pushButton_DeleteFile_clicked();

    void on_pushButton_Sync_clicked();

    void on_pushButton_Refresh_clicked();

    void on_pushButton_Reboot_clicked();

private:
    Ui::MainWindow *ui;
    RemarkableUserData * reMarkable;
    RemarkableSSH * rSSH;
};
#endif // MAINWINDOW_H
