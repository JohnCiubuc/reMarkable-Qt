#include "remarkableuserdata.h"

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
    for(auto s : pdfs)
    {
        //just name
        s.chop(4);

//        db s;
//        db  homeDirectory.entryList(QStringList() << s+".*", QDir::Files);
        for (auto fileDescriptor : homeDirectory.entryList(QStringList() << s+".*", QDir::Files))
        {
            if(fileDescriptor.contains("metadata"))
            {
                QFile f(homeDirectory.path() + "/"+  fileDescriptor);
                if(f.open(QFile::ReadOnly))
                    RemarkableFileContent rFC(f.readAll());
            }
        }
    }
}
