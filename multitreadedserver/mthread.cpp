#include "mthread.h"

mthread::mthread(int ID, QObject *parent):QThread(parent){
    this->socketdescriptor = ID;


}

void mthread::run(){
    qDebug() << socketdescriptor << " starting thread" ;
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketdescriptor)){
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyread()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketdescriptor << " client connected";

    exec();
}

void mthread::readyread(){
    QByteArray data = socket->readAll();
    qDebug() << socketdescriptor << " data in: " << data;

    socket->write(data);
}

void mthread::disconnected(){
    qDebug() << socketdescriptor << " client disconnected";
    socket->deleteLater();
    exit(0);
}


