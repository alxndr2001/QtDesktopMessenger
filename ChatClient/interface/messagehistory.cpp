#include "messagehistory.h"

MessageHistory::MessageHistory(QWidget *parent, Client *client) : QWidget(parent), client_(client) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    setLayout(mainLayout);
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QWidget *containerWidget = new QWidget(scrollArea);
    containerLayout = new QVBoxLayout(containerWidget);
    containerLayout->setAlignment(Qt::AlignTop);
    containerWidget->setLayout(containerLayout);
    scrollArea->setWidget(containerWidget);
    mainLayout->addWidget(scrollArea);
}

void MessageHistory::addMessage(const QString &text, bool isSender)
{
    Message* messageWidget = new Message(this, text, isSender);
    QHBoxLayout *messageLayout = new QHBoxLayout();
    if (isSender) {
        messageLayout->addStretch();
        messageLayout->addWidget(messageWidget);
    } else {
        messageLayout->addWidget(messageWidget);
        messageLayout->addStretch();
    }
    containerLayout->addLayout(messageLayout);
}
