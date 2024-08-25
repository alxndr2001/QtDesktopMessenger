#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QObject>
#include <memory>

#include "chatlist.h"
#include "client/client.h"
#include "messagehistory.h"

class ChatWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWindow(Client* client, const QString& chatName, QWidget *parent = nullptr);
    explicit ChatWindow(QWidget *parent = nullptr);

    QPushButton* sendButton; // Кнопка отправки сообщения
public slots:
    void getMessage();
signals:
    void sendMessage(QString& msg);
private:
    Client* client_;
    QString chatName; // Имя чата
    QLabel* chatNameLabel;
    QLineEdit *messageInput; // Поле ввода сообщения
    MessageHistory* msghistory;
};

#endif // CHATWINDOW_H
