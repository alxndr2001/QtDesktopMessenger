#ifndef CHATLIST_H
#define CHATLIST_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QPointer>
#include <QSplitter>

#include "chatwindow.h"

class ChatList : public QWidget
{
    Q_OBJECT
public:
    explicit ChatList(QWidget *parent = nullptr);

    void addChat(const QString& chatName);
    QListWidget* chatListWidget; //Окно чатов
private slots:
    void onChatSelected(QListWidgetItem* item);
    void searchChat(const QString& chatName);
signals:
    void openChat(const QString& chatName);
private:
    QVBoxLayout* layout; //Разметка
    QLineEdit* searchChatLabel; //Поиск чата
};

#endif // CHATLIST_H
