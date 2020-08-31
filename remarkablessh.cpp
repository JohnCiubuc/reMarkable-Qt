#include "remarkablessh.h"


RemarkableSSH::RemarkableSSH(QString ip)
{
    login = "root@"+ip;
    ssh = new QProcess;
    connect(ssh, &QProcess::readyReadStandardOutput, this, &RemarkableSSH::readyReadStandardOutput);

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

void RemarkableSSH::readyReadStandardOutput()
{
    db ssh->readAllStandardOutput();
//    ssh->write("ls");
}
