#include "session.h"

Session::Session(QTcpSocket *socket, QObject *parent) : QObject(parent), socket_(socket) {
    connect(socket_, &QTcpSocket::readyRead, this, &Session::onReadyRead);
    connect(socket_, &QTcpSocket::disconnected, this, &Session::onDisconnected);
}

void Session::setSessionId(QString uuid)
{
    this->uuid = uuid;
}

void Session::provideMessage(QString message)
{
    // Enable SSL for messages
    QByteArray data = message.toUtf8();
    socket_->write(data);
}

void Session::provideInfo(QString info)
{
    QByteArray data = info.toUtf8();
    socket_->write(data);
}

QString Session::getSessionId()
{
    return this->uuid;
}

void Session::onRetryAuth() {
    if(!auth)
        procAuth();
}

void Session::procAuth() // !!! Create QFuture async authorization
{
    QByteArray data = socket_->readAll();
    QString credentials = QString::fromUtf8(data);

    auto isValidCredentionals = [](const QString& credentials)->bool{
        QString validCredentionals = "username:password";
        return credentials.trimmed() == validCredentionals;
    };

    if(isValidCredentionals(credentials)) {
        auth = true;
        socket_->write("Authorization successful");
    } else {
        socket_->write("Authorization failed");
    }

}

void Session::onReadyRead()
{
    if(!auth) {
        // If user has not logged
        if(socket_->bytesAvailable() > 0)
            procAuth();
    } else {
        if(socket_->bytesAvailable() > 0)
            handleData();
        // If user has already logged
        // Provide him access to message dispatching methods

    }
}

void Session::handleData()
{
    // Message case:
    QString data(socket_->readAll());
    QString message;
    QString clientTo;

    QStringList clientFrom_message = data.split(':');
    if(clientFrom_message.size() == 2) {
        clientTo = clientFrom_message[0];
        message = clientFrom_message[1];
        emit sendMessage(this->uuid, clientTo, message);
    } else {
        qDebug() << this->uuid << " : Incorrect str format! ";
    }
}

void Session::onDisconnected()
{
    emit clientDisconnected(this);
}
