#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
class sockettest : public QObject
{
    Q_OBJECT
public:
    explicit sockettest(QObject *parent = nullptr);
    void connect();
signals:

public slots:
private:
    QTcpSocket *socket;
};

#endif // SOCKETTEST_H
