#include "remarkablefilecontent.h"

RemarkableFileContent::RemarkableFileContent(QObject *parent) : QObject(parent)
{

}

RemarkableFileContent::RemarkableFileContent(QByteArray contentJson)
{

    doc = QJsonDocument::fromJson(contentJson);

    db fileName();
}

const QString RemarkableFileContent::fileName()
{
    return doc["visibleName"].toString();
}
