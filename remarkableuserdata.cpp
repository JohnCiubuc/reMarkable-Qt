#include "remarkableuserdata.h"

QStringList RemarkableUserData::getPDFs()
{
    QStringList pdfs;
    for (auto rFC : remarkableFiles)
        pdfs << rFC->getFileDisplayName();
    return pdfs;
}

RemarkableUserData::RemarkableUserData(QObject *parent) : QObject(parent)
{

}

void RemarkableUserData::setHomeDir(QString hd)
{
    homeDirectory.setPath(hd + ".local/share/remarkable/xochitl/");
}

QDir RemarkableUserData::getHomeDir()
{
    return homeDirectory;
}

const QString RemarkableUserData::getUUIDFromName(QString fileName)
{
    for (auto rFC : remarkableFiles)
        if(rFC->getFileDisplayName() == fileName)
            return rFC->getFileUUID();

    return QString();
}

QString RemarkableUserData::generateContent(QString uuid)
{

    QJsonObject extraMetaData;
    extraMetaData["LastColor"] = "Black";
    extraMetaData["LastTool"] = "Ballpoint";
    extraMetaData["ThicknessScale"] = "1";

    QJsonObject content;
    content["extraMetadata"] = extraMetaData;
    content["fileType"] = "pdf";
    content["fontName"] = "";
    content["lastOpenedPage"] = 0;
    content["lineHeight"] = -1;
    content["margins"] = 100;
    content["pageCount"] = 1;
    content["textScale"]= 1;
    content["textAlignment"] = "left";
    content["textScale"] = 1;
    QJsonObject transform;

    transform["m11"] =1;
    transform["m12"]= 1;
    transform["m13"]=1;
    transform["m21"]= 1;
    transform["m22"]= 1;
    transform["m23"]= 1;
    transform["m31"]= 1;
    transform["m32"]=1;
    transform["m33"] =1;
    content["transform"] = transform;
    return  QJsonDocument(content).toJson();
}

QString RemarkableUserData::generateMetadata(QString fileName)
{
    QJsonObject doc;
    doc["deleted"] = false;
    doc["lastModified"] =  QString::number(int(std::time(0)) * 1000., 'g', 14);
    doc["metadatamodified"] = false;
    doc["modified"] = false;
    doc["parent"] = "";
    doc["pinned"] = false;
    doc["synced"] = false;
    doc["type"] = "DocumentType";
    doc["version"] = 0;
    doc["visibleName"] = fileName;
    return QJsonDocument(doc).toJson();
}

QString RemarkableUserData::generatePagedata(QString uuid)
{

    return QString("Blank");
}


void RemarkableUserData::startDebug()
{
    remarkableFiles.clear();
    // Temporary. Will iterate all uuids and get info
    // for now it's for my use case of pdfs only

    QStringList pdfs = homeDirectory.entryList(QStringList() << "*.pdf", QDir::Files);
    for(auto fileUUID : pdfs)
    {
        //just get the name/uuid
        fileUUID.chop(4);
        for (auto fileDescriptor : homeDirectory.entryList(QStringList() << fileUUID+".*", QDir::Files))
        {
            if(fileDescriptor.contains("metadata"))
            {
                QFile f(homeDirectory.path() + "/"+  fileDescriptor);
                if(f.open(QFile::ReadOnly))
                    remarkableFiles << new RemarkableFileContent(f.readAll(), fileUUID);
            }
        }
    }
    emit ready();
}
