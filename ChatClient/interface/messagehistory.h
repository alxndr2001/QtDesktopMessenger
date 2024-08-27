#ifndef MESSAGEHISTORY_H
#define MESSAGEHISTORY_H

#include <QVBoxLayout>
#include <QScrollArea>
#include <QObject>
#include <QWidget>

#include "client/client.h"
#include "message.h"

class MessageHistory : public QWidget
{
    Q_OBJECT
public:
    MessageHistory(QWidget* parent, Client* client);
    void addMessage(const QString& text, bool isSender);
private:
    Client* client_;
    QVBoxLayout* messagesLayout; // Messages layout which uses to add messages in
};

#endif // MESSAGEHISTORY_H
