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
    QScrollArea* scrollArea;
    QVBoxLayout* vlayout;
    QVBoxLayout *containerLayout;

};

#endif // MESSAGEHISTORY_H
