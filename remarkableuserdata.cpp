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

void RemarkableUserData::startDebug()
{
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
