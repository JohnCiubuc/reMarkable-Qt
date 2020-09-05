#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rSSH = new RemarkableSSH("10.11.99.1");

    rSSH->mountToTemp();

    reMarkable = new RemarkableUserData(this);
    connect(reMarkable, &RemarkableUserData::ready, this, &MainWindow::remarkableReady);
    // Delay for mounting

    QTimer* timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [this, timer]()
    {
        QDir dir(rSSH->getHomeDir());
        if(dir.exists())
        {
            reMarkable->setHomeDir(rSSH->getHomeDir());
            reMarkable->startDebug();
            timer->deleteLater();
        }
    });
    connect(timer, &QTimer::timeout, timer, &QTimer::deleteLater);
    timer->start(100);

}

MainWindow::~MainWindow()
{
    rSSH->unmountFromTemp();
    delete ui;
}

void MainWindow::remarkableReady()
{

    ui->listWidget->clear();
    widgetMap.clear();
    // Remarkable has all files (pdfs currently)
    for (auto string : reMarkable->getPDFs())
    {
        QListWidgetItem * i = new QListWidgetItem;
        i->setText(string->getFileDisplayName());
        i->setIcon(QIcon(":/thumbnail/Images/pdf.png"));
        ui->listWidget->addItem(i);
        widgetMap.insert(i, string);
    }
    for (auto folder : reMarkable->getFolders())
    {
        QListWidgetItem * i = new QListWidgetItem;
        i->setText(folder->getFileDisplayName());
        i->setIcon(folder->getFileUUID() == "parent" ?
                   QIcon(":/thumbnail/Images/user-home.png") :
                   QIcon(":/thumbnail/Images/folder-documents.png"));
        ui->listWidget->addItem(i);
        widgetMap.insert(i, folder);
    }
    for (auto file : reMarkable->getFiles())
    {
        QListWidgetItem * i = new QListWidgetItem;
        i->setText(file->getFileDisplayName());
        i->setIcon(QIcon(":/thumbnail/Images/x-office-document.png"));
        ui->listWidget->addItem(i);
        widgetMap.insert(i, file);
    }
}


void MainWindow::on_pushButton_ImportNewFile_clicked()
{
    auto fileName = QFileDialog::getOpenFileName(this,
                    tr("Open PDF"), QStandardPaths::displayName(QStandardPaths::HomeLocation), tr("PDF Files (*.pdf)"));

    if(fileName.isEmpty()) return;


    uuid_t uuid;
    uuid_generate(uuid);

    char uuid_str[37];
    uuid_unparse_lower(uuid, uuid_str);

    QString uuid_s = QString(uuid_str);

    QFile source(fileName);
    // TODO:
    QString out = reMarkable->getHomeDir().path() + "/" + uuid_s + ".pdf";
    QFileInfo fileInfo(source.fileName());
    QFile meta(reMarkable->getHomeDir().path() + "/" + uuid_s + ".metadata");
    if(meta.open(QFile::WriteOnly))
    {
        meta.write(reMarkable->generateMetadata(fileInfo.fileName()).toLocal8Bit());
        meta.close();
    }
    meta.setFileName(reMarkable->getHomeDir().path() + "/" + uuid_s + ".content");
    if(meta.open(QFile::WriteOnly))
    {
        meta.write(reMarkable->generateContent(fileInfo.fileName()).toLocal8Bit());
        meta.close();
    }
    QFile::copy(fileName, out);

    reMarkable->generateThumbnail(uuid_s, fileName);

    ui->listWidget->clear();
    reMarkable->startDebug();
}

void MainWindow::on_pushButton_DeleteFile_clicked()
{
    for(auto a: ui->listWidget->selectedItems())
    {
        auto uuid = reMarkable->getUUIDFromName( a->text());
        QFile config(reMarkable->getHomeDir().path() + "/" + uuid + ".metadata");
        if(config.open(QFile::ReadWrite))
        {
            QJsonDocument doc = QJsonDocument::fromJson(config.readAll());
            QJsonObject obj = doc.object();
            obj["deleted"] = true;
            config.resize(0);
            config.write(QJsonDocument(obj).toJson());
            config.close();
            QFile::remove(reMarkable->getHomeDir().path() + "/" + uuid + ".pdf");
        }
    }
    ui->listWidget->clear();
    reMarkable->startDebug();
}

void MainWindow::on_pushButton_Sync_clicked()
{
    db "restartXochitl";
    rSSH->restartXochitl();
}

void MainWindow::on_pushButton_Refresh_clicked()
{
    db "refreshListView";
    ui->listWidget->clear();
    reMarkable->startDebug();
}

void MainWindow::on_pushButton_Reboot_clicked()
{
    db "rebootDevice";
    rSSH->rebootDevice();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    RemarkableFileContent* rfc = widgetMap.value(item);
    if(rfc->getType() == "CollectionType")
    {
        db "Enter Folder - " << rfc->getFileDisplayName();
        reMarkable->enterFolder(rfc);
    }
}
