#include <QCoreApplication>
#include "sockettest.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    sockettest mtest;
    mtest.test();
    return a.exec();
}
