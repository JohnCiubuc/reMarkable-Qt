#ifndef REMARKABLEUSERDATA_H
#define REMARKABLEUSERDATA_H

#include <QObject>
#include <QFile>
#include <QDir>
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

    void startDebug();
signals:
    void ready();
private:
    QDir homeDirectory;

    QList<RemarkableFileContent*> remarkableFiles;
};

#endif // REMARKABLEUSERDATA_H
