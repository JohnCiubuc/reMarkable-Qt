#include "remarkableuserdata.h"



const QList<RemarkableFileContent *> RemarkableUserData::getFolders()
{
    if(parentUUID.isEmpty())
    {
        QList<RemarkableFileContent*> out;
        for(auto folder:remarkableFolders)
        {
            if(folder->getParent().isEmpty())
                out << folder;
        }
        return out;
    }
    else
    {
        QList<RemarkableFileContent*> out;
        QJsonObject temp;
        temp["parent"] = parentUUID;
        temp["type"] = "CollectionType";
        temp["visibleName"] = "Go Back";
        out << new RemarkableFileContent(QJsonDocument(temp).toJson(), "parent");
        for(auto folder:remarkableFolders)
        {
            if(folder->getParent() == parentUUID)
                out << folder;
        }
        return out;
    }
    return QList<RemarkableFileContent*>();
}

void RemarkableUserData::enterFolder(RemarkableFileContent *rfc)
{
    if(rfc->getFileUUID() == "parent")
    {
        for (auto folder:remarkableFolders)
        {
            if(folder->getFileUUID() == rfc->getParent())
            {
                parentUUID = folder->getParent();
                break;
            }
        }
    }
    else
        parentUUID = rfc->getFileUUID();
    emit ready();
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

void RemarkableUserData::generateThumbnail(QString uuid, QString fileNameAndPath)
{

    QStringList args;
    args << "-density";
    args << "300";
    args << fileNameAndPath+"'[0]'";
    args << "-colorspace";
    args << "Gray";
    args << "-separate";
    args << "-average";
    args << "-shave";
    args << "5%x5%";
    args << "-resize";
    args << "280x374";
    args << getHomeDir().path() + "/" + uuid + ".thumbnails/0.jpg";
    QProcess *p=new QProcess;
    p->start("convert", args);
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
    // 'Folders'
    QStringList metadata = homeDirectory.entryList(QStringList() << "*.metadata", QDir::Files);
    for(auto fileUUID : metadata)
    {
        //just get the name/uuid
//        fileUUID.chop(10);

        QFile f(homeDirectory.path() + "/"+  fileUUID);
        if(f.open(QFile::ReadOnly))
        {

            auto rfc =  new RemarkableFileContent(f.readAll(), fileUUID.mid(0,fileUUID.size()-9));
            if(rfc->getType() == "CollectionType")
                remarkableFolders << rfc;
            // not true for everything
            else
                delete rfc;
            f.close();
        }
//        for (auto fileDescriptor : homeDirectory.entryList(QStringList() << fileUUID+".*", QDir::Files))
//        {
//            if(fileDescriptor.contains("metadata"))
//            {
//                QFile f(homeDirectory.path() + "/"+  fileDescriptor);
//                if(f.open(QFile::ReadOnly))
//                    remarkableFiles << new RemarkableFileContent(f.readAll(), fileUUID);
//            }
//        }
    }
    for (auto folder : remarkableFolders)
    {
        db folder->getFileDisplayName() <<" --- "<< folder->getFileUUID();
    }
    emit ready();
}
