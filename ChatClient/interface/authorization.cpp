#include "authorization.h"

Authorization::Authorization(QWidget *parent, Client* client) : _client(client)
{
    mainLayout = new QVBoxLayout(this);

    mainLayout->addStretch();

    authForm = new QWidget(this);
    authFormLayout = new QHBoxLayout(authForm);
    authForm->setLayout(authFormLayout);

    authFormLayout->addStretch();

    QWidget* formWidget = new QWidget(this);
    QVBoxLayout* formLayout = new QVBoxLayout(formWidget);

    usernameLE = new QLineEdit(this);
    usernameLE->setFixedSize(200, 30);

    passwordLE = new QLineEdit(this);
    passwordLE->setFixedSize(200, 30);

    passwordLE->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Авторизироваться", this);
    loginButton->setFixedSize(200, 30);

    authName = new QLabel("Начните общение");
    authName->setAlignment(Qt::AlignCenter);

    errorLabel = new QLabel("");
    errorLabel->setStyleSheet(" color: red ");

   // authName->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    usernameLE->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    passwordLE->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    loginButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    formLayout->addWidget(authName);
    formLayout->addWidget(usernameLE);
    formLayout->addWidget(passwordLE);
    formLayout->addWidget(loginButton);
    formLayout->addWidget(errorLabel);

    authFormLayout->addWidget(formWidget);
    authFormLayout->addStretch();

    mainLayout->addWidget(authForm);
    mainLayout->addStretch();

    connect(loginButton, &QPushButton::clicked, this, &Authorization::handleAuthorization);
    connect(this, &Authorization::sendLoginRequest, _client, &Client::handleLogin);
    connect(_client, &Client::authorizationFailed, this, &Authorization::onAuthorizationFailed);

    /* Установка темной темы */
    _setDarkTheme();
}

void Authorization::handleAuthorization()
{
    emit sendLoginRequest(usernameLE->text(), passwordLE->text());
}

void Authorization::onAuthorizationFailed()
{
    usernameLE->setStyleSheet("QLineEdit { border: 2px solid red; }");
    passwordLE->setStyleSheet("QLineEdit { border: 2px solid red; }");
    errorLabel->setText("Invalid username or password.");
    QTimer::singleShot(3000, this, [&](){
        usernameLE->setStyleSheet("");
        passwordLE->setStyleSheet("");
        errorLabel->setText("");
    });
}

void Authorization::_setDarkTheme()
{
    setStyleSheet(
                "QWidget {"
                "   background-color: #2f3136;"
                "   color: white;"
                "}"
                "QLineEdit {"
                "   background-color: #40444b;"
                "   color: white;"
                "   border: 1px solid #7289da;"
                "   border-radius: 5px;"
                "   padding: 5px;"
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
                "QLabel {"
                "   color: white;"
                "   padding: 5px;"
                "}"
                "QLabel#errorLabel {"
                "   color: red;"
                "}"
                "QWidget#authName {"
                "   font-size: 18px;"
                "   font-weight: bold;"
                "   padding: 10px;"
                "}"
                );
}
