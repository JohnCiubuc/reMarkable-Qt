#include "remarkablefilecontent.h"

RemarkableFileContent::RemarkableFileContent(QObject *parent) : QObject(parent)
{

}

RemarkableFileContent::RemarkableFileContent(QByteArray contentJson, QString uuid)
{

    doc = QJsonDocument::fromJson(contentJson);
    fileUUIDString = uuid;
}

const QString RemarkableFileContent::getFileDisplayName()
{
    return doc["visibleName"].toString();
}

const QString RemarkableFileContent::getFileUUID()
{
    return fileUUIDString;
}
