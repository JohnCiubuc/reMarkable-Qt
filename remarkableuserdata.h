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
    QStringList getPDFs();
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

    QList<RemarkableFileContent*> remarkableFiles;
};

#endif // REMARKABLEUSERDATA_H
