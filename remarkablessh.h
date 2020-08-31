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
public slots:
    void restartXochitl();
    void stopXochitl();
    void startXochitl();
    void rebootDevice();
    void shutdownDevice();
private slots:
    void readyReadStandardOutput();
signals:
private:
    QProcess * ssh;
    QString login;
};

#endif // REMARKABLESSH_H
