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
    explicit RemarkableFileContent(QObject *parent = nullptr);

    RemarkableFileContent(QByteArray contentJson);

    const QString fileName();
signals:

private:
    QJsonDocument doc;
};

#endif // REMARKABLEFILECONTENT_H
