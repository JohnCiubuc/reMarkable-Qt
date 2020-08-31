#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QString remarkDataDir = "/home/inathero/ReMarkable/home/root/";


    reMarkable = new RemarkableUserData(this);
    connect(reMarkable, &RemarkableUserData::ready, this, &MainWindow::remarkableReady);
    reMarkable->setHomeDir(remarkDataDir);
    reMarkable->startDebug();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::remarkableReady()
{

    // Remarkable has all files (pdfs currently)
    QStringList allPDfs = reMarkable->getPDFs();
    for (auto string : allPDfs)
    {
        QListWidgetItem * i = new QListWidgetItem;
        i->setText(string);
        i->setIcon(QIcon(":/thumbnail/Images/pdf.png"));
        ui->listWidget->addItem(i);
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

    ui->listWidget->clear();
    reMarkable->startDebug();
}

void MainWindow::on_pushButton_DeleteFile_clicked()
{
    for(auto a: ui->listWidget->selectedItems())
    {
        auto uuid = reMarkable->getUUIDFromName( a->text());
    }
}
