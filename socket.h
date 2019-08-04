#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>
#include "return_codes.h"
#include <QObject>
#include <QHostAddress>

class Socket : public QObject
{
public:
    Socket();
    ConnectionStatus connect_run(QString ip, QString port);
private:
    QTcpSocket* socket_;

private slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
};

#endif // SOCKET_H
