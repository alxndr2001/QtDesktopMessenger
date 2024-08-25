#include "chatwindow.h"


ChatWindow::ChatWindow(Client* client, const QString& chatName, QWidget *parent)
    : QWidget(parent), client_(client), chatName(chatName)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    chatNameLabel = new QLabel(chatName, this);
    chatNameLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(chatNameLabel);

    msghistory = new MessageHistory(this, client_);
    layout->addWidget(msghistory);

    QHBoxLayout* messageInputLayout = new QHBoxLayout();
    layout->addLayout(messageInputLayout);

    messageInput = new QLineEdit(this);
    messageInput->setPlaceholderText("Введите сообщение...");
    messageInputLayout->addWidget(messageInput);

    sendButton = new QPushButton(this);
    sendButton->setText(">");
    messageInputLayout->addWidget(sendButton);

    setLayout(layout);

    setMinimumSize(400, 300);
    setWindowTitle("Чат");

    connect(sendButton, &QPushButton::clicked, this, &ChatWindow::getMessage);
    connect(this, &ChatWindow::sendMessage, client_, &Client::onSendMessage);
}

ChatWindow::ChatWindow(QWidget*)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *chatTitle = new QLabel("Select a chat to start messaging", this);
    chatTitle->setAlignment(Qt::AlignCenter); // Центрирование текста
    layout->addWidget(chatTitle);
    setMinimumSize(400, 300);
}

void ChatWindow::getMessage()
{
    QString msg = chatNameLabel->text() + ":" + messageInput->text();
    emit sendMessage(msg);
}

