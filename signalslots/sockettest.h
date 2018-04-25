#ifndef SOCKETTEST_H
#define SOCKETTEST_H
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>

class sockettest : public QObject
{
    Q_OBJECT
public:
    explicit sockettest(QObject *parent = nullptr);
    void test();
signals:


public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
private:
    QTcpSocket *socket;
};

#endif // SOCKETTEST_H
