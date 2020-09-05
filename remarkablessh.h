#ifndef REMARKABLESSH_H
#define REMARKABLESSH_H

#include <QObject>
#include <QProcess>
#include "utilities.h"

class RemarkableSSH : public QObject
{
    Q_OBJECT
public:
    explicit RemarkableSSH(QString ip);
    const QString getHomeDir();
public slots:
    void restartXochitl();
    void stopXochitl();
    void startXochitl();
    void rebootDevice();
    void shutdownDevice();
    void mountToTemp();
    void unmountFromTemp();

    void runDebug();
private slots:
    void readyReadStandardOutput();
    void finished(int exitCode);
signals:
private:
    QProcess * ssh;
    QString login;
    QString uuid_dir;
    bool bUmount = false;
};

#endif // REMARKABLESSH_H
