#ifndef REMARKABLEFILECONTENT_H
#define REMARKABLEFILECONTENT_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "utilities.h"

class RemarkableFileContent : public QObject
{
    Q_OBJECT
public:
//    explicit RemarkableFileContent(QObject *parent = nullptr);

    RemarkableFileContent(QByteArray contentJson, QString uuid= "");

    const QString getFileDisplayName()
    {
        return doc["visibleName"].toString();
    }
    const QString getFileUUID()
    {
        return fileUUIDString;
    }
    const QString getType()
    {
        return doc["type"].toString();
    }
    const QString getParent()
    {
        return doc["parent"].toString();
    }
signals:

private:
    QJsonDocument doc;
    QString fileUUIDString;
};

#endif // REMARKABLEFILECONTENT_H
