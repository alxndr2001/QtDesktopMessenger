#include "server.h"

#include <QUuid>
#include <QHashIterator>

Server::Server(QObject *parent) : QTcpServer(parent) {}

void Server::startServer(QHostAddress address, uint16_t port)
{
    if(this->listen(address, port)) {
        qDebug() << "Server started on " << address << ":" << port;
    } else {
        qDebug() << "Failed to start server:" << this->errorString();
    }
}

void Server::onClientDisconnected(Session* session)
{
    qDebug() << "Client " << session->getSessionId() << " disconnected";
    sessions.remove(session->getSessionId());
    qDebug() << "Current sessions: " << sessions;
}

void Server::dispatchMessage(QString &from, QString &to, QString message)
{
    if(sessions.contains(to)) {
        qDebug() << "Client " << from << " is going to send message {" << message << "} to client " << to;
        auto sessionTo = sessions.find(to);
        sessionTo.value()->provideMessage(message);
    }
    else if(!sessions.contains(to)) {
        // Send to client that there is no such client available rn
        // !!! Realise system to send offline clients messages
        qDebug() << "There is no such client as " << to;
        auto sessionFrom = sessions.find(from);
        sessionFrom.value()->provideInfo("There is no such client!");
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    auto generateUuid = []()->QString {
        QUuid uuid = QUuid::createUuid();
        return uuid.toString();
    };

    QTcpSocket* clientSocket = new QTcpSocket(this);
    if(clientSocket->setSocketDescriptor(socketDescriptor)) {
        Session* session = new Session(clientSocket, this);

        QString uuid = generateUuid();
        session->setSessionId(uuid);
        sessions.insert(uuid, session);

        connect(session, &Session::clientDisconnected, this, &Server::onClientDisconnected);
        connect(session, &Session::sendMessage, this, &Server::dispatchMessage);
        qDebug() << "Current sessions: " << sessions;
    } else {
        qDebug() << "wrong socket";
    }
}
