#include <QCoreApplication>
#include "sockettest.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    sockettest ctest;
    ctest.connect();
    return a.exec();
}
