#ifndef MTHREAD_H
#define MTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class mthread : public QThread
{
    Q_OBJECT
public:
    explicit mthread(int ID, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:
    void readyread();
    void disconnected();
private:
    QTcpSocket *socket;
    qintptr sockeDescriptor;//socket id no from the os
};

#endif // MTHREAD_H
