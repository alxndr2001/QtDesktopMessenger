#include "chatlist.h"
#include "QDebug"

ChatList::ChatList(QWidget *parent) : QWidget(parent)
{
    chatListWidget = new QListWidget(this);
    searchChatLabel = new QLineEdit(this);
    layout = new QVBoxLayout(this);

    layout->addWidget(searchChatLabel);
    layout->addWidget(chatListWidget);
    setLayout(layout);

    connect(chatListWidget, &QListWidget::itemClicked, this, &ChatList::onChatSelected);
    connect(searchChatLabel, &QLineEdit::editingFinished, [=]() {
        searchChat(searchChatLabel->text());
    });

    searchChatLabel->setPlaceholderText("Поиск");
    searchChatLabel->setAlignment(Qt::AlignCenter); // Центрирование текста
}

void ChatList::addChat(const QString& chatName)
{
    chatListWidget->addItem(chatName);
}

void ChatList::onChatSelected(QListWidgetItem *item)
{
    openChat(item->text());
}

void ChatList::searchChat(const QString &chatName)
{
    openChat(chatName);
}
