#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QWidget>
#include "chatlist.h"
#include "chatwindow.h"
#include "client/client.h"

class MainInterface : public QWidget
{
    Q_OBJECT
public:
    MainInterface (QWidget* parent, Client* client);
private:
    void _setDarkTheme(); // Установка темной темы
    Client* client_;
    ChatWindow* newChatWindow = nullptr;
    QHBoxLayout* layout;
    QSplitter* splitter; // Разелитель
    ChatList* chatList; // Список чатов
    QLineEdit* search; // Поиск чатов
public slots:
    void openOpenChatWidget(const QString &chatName);
};

#endif // MAININTERFACE_H
