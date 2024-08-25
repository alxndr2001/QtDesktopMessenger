#include "client.h"

Client::Client(QObject *parent) : QObject(parent) {
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &Client::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Client::onDisconnected);
    connectToHost("127.0.0.1", 1234);
}

void Client::connectToHost(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
}

void Client::onConnected()
{
    qDebug() << "Connected to server";
}

void Client::onDisconnected()
{
    qDebug() << "Disconnected from server";
}

void Client::onReadyRead()
{
    QString info = socket->readAll();
    qDebug() << info;
    if(info == "Authorization successful")
        emit authorizedSuccessfully();
    else if(info == "Authorization failed")
        emit authorizationFailed();
}

void Client::handleLogin(const QString& login, const QString& password)
{
    QString logpas = login + ":" + password;
    QByteArray data = logpas.toUtf8();
    socket->write(data);
}

void Client::onSendMessage(QString &message)
{

}

void Client::receieveMessage()
{

}
