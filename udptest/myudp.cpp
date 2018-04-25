#include "myudp.h"

myudp::myudp(QObject *parent) : QObject(parent){
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1234);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

}

void myudp::sayhello(){
    QByteArray data;
    data.append("hello world");
    socket->writeDatagram(data,QHostAddress::LocalHost,1234);

}

void myudp::readyRead(){
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderport;
    socket->readDatagram(buffer.data(),buffer.size(),&sender,&senderport);

    qDebug() << "message from: " << sender << "\ton port: " << senderport;
    qDebug() << "message:\t" << buffer;
}
