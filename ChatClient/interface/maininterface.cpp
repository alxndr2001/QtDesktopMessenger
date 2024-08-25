#include "maininterface.h"

MainInterface::MainInterface(QWidget *parent, Client* client) : QWidget(parent), client_(client)
{
    /* Горизонтальная разметка */
    layout = new QHBoxLayout(this);
    /* Сплиттер */
    splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Horizontal);
    /* Список чатов */
    chatList = new ChatList(this);
    //ChatWindow* ChatWindowEmpty = new ChatWindow;

    ChatWindow* chatWindow = new ChatWindow(this);
    splitter->addWidget(chatList); // Добавить список чатов слева
    splitter->addWidget(chatWindow); // Добавить окно чата справа

    layout->addWidget(splitter);

    // TEST
    for(int i = 0; i < 40; ++i)
    {
        chatList->addChat("Chat " + QString::number(i));
    }

    connect(chatList, &ChatList::openChat, this, &MainInterface::openOpenChatWidget);

    /* темная тема */
    _setDarkTheme();
}

void MainInterface::openOpenChatWidget(const QString &chatName)
{
    QList<QListWidgetItem*> items = chatList->chatListWidget->findItems(chatName, Qt::MatchFixedString);

    if(!items.isEmpty())
    {
        QWidget* currentWidget = splitter->widget(1); //Pointer to curr widget
        newChatWindow = new ChatWindow(client_, items.at(0)->text(), this);
        splitter->replaceWidget(1, newChatWindow);
        delete currentWidget; //Clear replaced chat memory
        chatList->chatListWidget->setCurrentItem(items.at(0));
    }
}


void MainInterface::_setDarkTheme()
{
    setStyleSheet(
                "QSplitter::handle {"
                "   background-color: #36393f;"
                "   border: 1px solid #444;"
                "   width: 6px;"
                "}"
                "QWidget {"
                "   background-color: #2f3136;"
                "}"
                "QListWidget {"
                "   background-color: #36393f;"
                "   color: white;"
                "   border: 1px solid #43454f;"
                "}"
                "QListWidget::item {"
                "   padding: 10px;"
                "}"
                "QListWidget::item:selected {"
                "   background-color: #4f545c;"
                "}"
                "QPushButton {"
                "   background-color: #7289da;"
                "   color: white;"
                "   border: none;"
                "   padding: 10px;"
                "   border-radius: 5px;"
                "}"
                "QPushButton:hover {"
                "   background-color: #5a6ad1;"
                "}"
                "QLineEdit {"
                "   background-color: #40444b;"
                "   color: white;"
                "   border: 1px solid #7289da;"
                "   border-radius: 5px;"
                "   padding: 5px;"
                "}"
                "QLabel {"
                "   color: white;"
                "}"
            );
}
