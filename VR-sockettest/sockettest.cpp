#include "sockettest.h"

sockettest::sockettest(QObject *parent) : QObject(parent)
{

}

void sockettest::connect(){
    //create a socket
    socket = new QTcpSocket(this);

    //connect
    socket->connectToHost("google.com",80);

    //test for connected
    if(socket->waitForConnected(300)){
        qDebug() << "connected";

        //send data
        socket->write("hello server\r\n\r\n\r\n\r\n");

        //recieve data
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(300);
        qDebug() << "reading: " << socket->bytesAvailable();
        qDebug() << socket->readAll();

        //close sockect
        socket->close();
    }
    else {
        qDebug() << "not connected";
    }



}
