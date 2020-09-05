#ifndef REMARKABLEUSERDATA_H
#define REMARKABLEUSERDATA_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QProcess>
#include "utilities.h"
#include "remarkablefilecontent.h"
class RemarkableUserData : public QObject
{
    Q_OBJECT
public slots:
    const QList<RemarkableFileContent*> getPDFs()
    {
        if(parentUUID.isEmpty()) return tempRemPdf;
        else return QList<RemarkableFileContent*>();
        QList<RemarkableFileContent*> out;

        //    QStringList pdfs;
        //    for (auto rFC : remarkableFiles)
        //        pdfs << rFC->getFileDisplayName();
        return tempRemPdf;
    }
    const QList<RemarkableFileContent*> getFolders();
    const QList<RemarkableFileContent*> getFiles();
    void enterFolder(RemarkableFileContent * rfc);
public:
    explicit RemarkableUserData(QObject *parent = nullptr);

    void setHomeDir(QString hd);

    QDir getHomeDir();
    const QString getUUIDFromName(QString fileName);

    QString generateContent(QString uuid);
    QString generateMetadata(QString fileName);
    QString generatePagedata(QString uuid);
    void generateThumbnail(QString uuid, QString fileNameAndPath);

    void startDebug();
signals:
    void ready();
private:
    QDir homeDirectory;

    QString parentUUID;
    QString grandParentUUID;
    QList<RemarkableFileContent*> remarkableFiles;
    QList<RemarkableFileContent*> tempRemPdf;
    QList<RemarkableFileContent*> remarkableNotes;
    QList<RemarkableFileContent*> remarkableFolders;
};

#endif // REMARKABLEUSERDATA_H
