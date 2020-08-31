#include "remarkablessh.h"


RemarkableSSH::RemarkableSSH(QString ip)
{
    login = "root@"+ip;
    ssh = new QProcess;
    connect(ssh, &QProcess::readyReadStandardOutput, this, &RemarkableSSH::readyReadStandardOutput);
//    connect(ssh, &QProcess::finished, this, &RemarkableSSH::finished);

}

const QString RemarkableSSH::getHomeDir()
{
    if(uuid_dir.isEmpty())
        return "";
    return "/tmp/" + uuid_dir + "/home/root/";
}

void RemarkableSSH::restartXochitl()
{
    ssh->start("ssh", QStringList() << login << "systemctl" << "restart" << "xochitl");
}

void RemarkableSSH::stopXochitl()
{
    ssh->start("ssh", QStringList() << login << "systemctl" << "stop" << "xochitl");
}

void RemarkableSSH::startXochitl()
{
    ssh->start("ssh", QStringList() << login << "systemctl" << "start" << "xochitl");
}

void RemarkableSSH::rebootDevice()
{
    ssh->start("ssh", QStringList() << login << "systemctl" << "reboot");
}

void RemarkableSSH::shutdownDevice()
{
    ssh->start("ssh", QStringList() << login <<"systemctl" << "shutdown" );
}

void RemarkableSSH::mountToTemp()
{
    if(uuid_dir.isEmpty())
    {
        uuid_t uuid;
        uuid_generate(uuid);

        char uuid_str[37];
        uuid_unparse_lower(uuid, uuid_str);

        uuid_dir = QString(uuid_str);


        QDir dir("/tmp/" + uuid_dir);
        dir.mkdir("/tmp/" + uuid_dir);
        ssh->start("sshfs", QStringList() << login + ":/" <<"/tmp/" + uuid_dir );
    }
}

void RemarkableSSH::unmountFromTemp()
{
    if(uuid_dir.isEmpty()) return;
    bUmount = true;

    ssh->start("umount", QStringList() << "/tmp/" + uuid_dir );
}

void RemarkableSSH::readyReadStandardOutput()
{
    db ssh->readAllStandardOutput();
    //    ssh->write("ls");
}

void RemarkableSSH::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    db "finished; Exitcode: " << exitCode;
    if(bUmount)
    {
        QDir dir("/tmp/" + uuid_dir);
        dir.rmdir("/tmp/" + uuid_dir);
        db "Removed: " << dir.path();
    }
}
