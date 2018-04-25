#ifndef MSERVER_H
#define MSERVER_H
#include <QTcpServer>
#include <QDebug>
#include "mthread.h"

class mserver : public QTcpServer
{
    Q_OBJECT
public:
   explicit mserver(QObject *parent = 0);
   void StartServer();

signals:

public slots:

private:
    void incomingConnection(qintptr socketdescriptor);

};

#endif // MSERVER_H
