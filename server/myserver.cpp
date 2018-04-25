#include "myserver.h"

myserver::myserver(QObject *parent) : QObject(parent){
    server = new QTcpServer(this);

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any,1234)){
        qDebug() << "server could not start";
    }
    else{
        qDebug() << "server started" ;

    }

}

void myserver::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("hello client");
    socket->flush();

    socket->waitForBytesWritten(300);
    socket->close();
}
