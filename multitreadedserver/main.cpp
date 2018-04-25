#include <QCoreApplication>
#include "mserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    mserver server;
    server.StartServer();
    return a.exec();
}
