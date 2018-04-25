#include <QCoreApplication>
#include "myudp.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    myudp server;
    myudp client;
    client.sayhello();
    return a.exec();
}
