#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include <QObject>
#include "session.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject* parent = nullptr);
    void startServer(QHostAddress address, uint16_t port);
public slots:
    void onClientDisconnected(Session* session);
    void dispatchMessage(QString &from, QString &to, QString message);
protected:
    void incomingConnection(qintptr socketDescriptor) override;
private:
    QHash<QString, Session*> sessions; // Сессии клиентов
    bool userNameRead;
};

#endif // SERVER_H
