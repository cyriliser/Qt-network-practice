#include "sockettest.h"

sockettest::sockettest(QObject *parent) : QObject(parent){

}

void sockettest::test(){
    //create socket
    socket = new QTcpSocket(this);

    //connect signals and slots
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));

    qDebug() << "connetcting...";

    //connect to host
    socket->connectToHost("ukzn.ac.za",80);


    //check connected
    if(!socket->waitForConnected(100)){//if no parameter waits indefinately
        qDebug() << "Error: " << socket->errorString();
    }
}

void sockettest::connected(){
    qDebug() << "connected";

    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");

}

void sockettest::disconnected(){
    qDebug() << "diconnected";

}

void sockettest::bytesWritten(qint64 bytes){
    qDebug() << "we wrote: " <<  bytes;

}

void sockettest::readyRead(){
    qDebug() << "reading...";
    qDebug() << socket->readAll();

}
