#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QTimer>

// !!! (1) Need an implementation of unique id of information providing to client: unique id for messages type, for tech information type, for errors type. (Maybe use ENUM)

class Session : public QObject
{
    Q_OBJECT
public:
    Session(QTcpSocket* socket, QObject* parent);
    void setSessionId(QString cliId); // Set session id (id is uuid)
    void provideMessage(QString message); // Provide messages from Cli to Cli (!!! make SSL later)
    void provideInfo(QString info); // Provide another information, to only messages. ??? Maybe merge in one class with provideMessage
    QString getSessionId(); // Get session id (id is uuid)
private:
    void handleData(); // Handling type of incoming data (message or ???)
    void procAuth(); // Provide user login to
    void onRetryAuth();
    bool auth; // authorized or not
    QString uuid; // Uniq user identificator
    QTcpSocket* socket_;
public slots:
    void onReadyRead();
    void onDisconnected();
signals:
    void clientDisconnected(Session* session);
    void sendMessage(QString& from, QString& to, QString message);
};

#endif // SESSION_H
