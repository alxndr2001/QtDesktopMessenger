#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>

class Client : public QObject {
    Q_OBJECT
public:
    explicit Client(QObject* parent = nullptr);
    void connectToHost(const QString& host, quint16 port);
private:
    QTcpSocket* socket;
private slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
public slots:
    void handleLogin(const QString& login, const QString& password);
    void onSendMessage(QString& message);
    void receieveMessage();
signals:
    void authorizedSuccessfully();
    void authorizationFailed();
};

#endif // CHATLIST_H
