#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTimer>
#include <QListWidgetItem>

#include <QDrag>
#include <QMimeData>
#include <QDropEvent>

#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
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

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    RemarkableUserData * reMarkable;
    RemarkableSSH * rSSH;
    QMap<QListWidgetItem *,  RemarkableFileContent*> widgetMap;
protected:
    // —— events ———————————————————————————
    /*
     * this event is called when the mouse enters the widgets area during a drag/drop operation
     */
    void dragEnterEvent(QDragEnterEvent *event);

    /**
     * this event is called when the mouse moves inside the widgets area during a drag/drop operation
     */
    void dragMoveEvent(QDragMoveEvent *event);

    /**
     * this event is called when the mouse leaves the widgets area during a drag/drop operation
     */
    void dragLeaveEvent(QDragLeaveEvent *event);

    /**
     * this event is called when the drop operation is initiated at the widget
     */
    void dropEvent(QDropEvent *event);


};
#endif // MAINWINDOW_H
