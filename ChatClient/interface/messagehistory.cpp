#include "messagehistory.h"

MessageHistory::MessageHistory(QWidget *parent, Client *client) : QWidget(parent), client_(client) {
    QScrollArea* messageScrollArea = new QScrollArea(this);

    QWidget* messagesContainer = new QWidget();
    messagesLayout = new QVBoxLayout(messagesContainer);

    messagesContainer->setLayout(messagesLayout);
    messageScrollArea->setWidget(messagesContainer);
    messageScrollArea->setWidgetResizable(true);
    messageScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    messagesLayout->setAlignment(Qt::AlignTop);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(messageScrollArea);
    this->setLayout(mainLayout);


    //messagesLayout->addWidget(lbl);
    // /*Adding feature to scroll messages history*/
    // scrollArea = new QScrollArea(this);
    // scrollArea->setWidgetResizable(true);
    // scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // mainLayout->addWidget(scrollArea);

    // QWidget* messages = new QWidget(scrollArea);
    // QVBoxLayout* messagesLayout = new QVBoxLayout();
    // messages->setLayout(messagesLayout);
    // scrollArea->setWidget(messages);
    // /*
    // QWidget *containerWidget = new QWidget(scrollArea);
    // containerLayout = new QVBoxLayout(containerWidget);
    // containerLayout->setAlignment(Qt::AlignTop);
    // containerWidget->setLayout(containerLayout);
    // scrollArea->setWidget(containerWidget);
    // mainLayout->addWidget(scrollArea);
    // */

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
    messagesLayout->addLayout(messageLayout);
}
