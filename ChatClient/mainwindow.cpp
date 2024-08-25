#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*Инициализация клиента*/
    client = new Client();
    clithread = new QThread(this);
    client->moveToThread(clithread);
    clithread->start();
    /*Инициализация формы переключения окна авторизации на итерфейс чатов*/
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    mainInterface = new MainInterface(this, client);
    authInterface = new Authorization(this, client);
    stackedWidget->addWidget(authInterface);
    stackedWidget->addWidget(mainInterface);
    stackedWidget->setCurrentWidget(authInterface);
    connect(client, &Client::authorizedSuccessfully, this, &MainWindow::onAuthorized);

    /*темная тема*/
    setStyleSheet (

    "QMainWindow {"
    "   background-color: #2f3136;"
    "   border: 1px solid #444;"
    "   border-radius: 8px;"
    "}"
                );
}

MainWindow::~MainWindow()
{
    clithread->quit();
    clithread->wait();
    delete clithread;
    delete ui;
}

void MainWindow::setDarkTheme()
{
    setStyleSheet (

    "QMainWindow {"
    "   background-color: #2f3136;"
    "   border: 1px solid #444;"
    "   border-radius: 8px;"
    "}"
                );
}

void MainWindow::onAuthorized()
{
    stackedWidget->setCurrentWidget(mainInterface);
}



