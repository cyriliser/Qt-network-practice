#include "mserver.h"

mserver::mserver(QObject *parent):QTcpServer(parent)
{

}

void mserver::StartServer(){
    if(!this->listen(QHostAddress::Any,1234)){
        qDebug() << "server could not start";
    }
    else{
        qDebug() << "listening....";

    }
}

void mserver::incomingConnection(socketDescriptor()){
    qDebug() << socketdescriptor << " connecting...";
    mthread *thread = new mthread(socketdescriptor,this);
    connect(thread,SIGNAL(finished()),SLOT(deleteLater()));
    thread->start();
}
