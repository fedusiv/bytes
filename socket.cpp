#include "socket.h"
#include <QDebug>
Socket::Socket()
{
    socket_ = new QTcpSocket(this);

    connect(socket_, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket_, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket_, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket_, SIGNAL(readyRead()),this, SLOT(readyRead()));


}

ConnectionStatus Socket::connect_run(QString ip, QString port)
{

    socket_->connectToHost(QHostAddress(ip), port.toUShort());
    if(!socket_->waitForConnected(5000))
    {
        return ConnectionStatus::Disconnected;
    }
    return  ConnectionStatus::Connected;
}

void Socket::send_command(CommandDescription desc)
{
    Q_UNUSED(desc);
}

void Socket::connected()
{
    qDebug() << "Connected";
}

void Socket::disconnected()
{

}

void Socket::bytesWritten(qint64 bytes)
{

}

void Socket::readyRead()
{

}
