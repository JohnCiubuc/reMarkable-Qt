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
public:
    explicit RemarkableUserData(QObject *parent = nullptr);

    void setHomeDir(QString hd);

    void startDebug();
signals:
private:
    QDir homeDirectory;

};

#endif // REMARKABLEUSERDATA_H
