#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>
#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

#include <utility>
#include "client/client.h"

class Authorization : public QWidget
{
    Q_OBJECT
public:
    Authorization(QWidget* parent, Client* client);
private:
    void _setDarkTheme(); // Установка темной темы
    QVBoxLayout* mainLayout;
    QHBoxLayout* authFormLayout;
    QLabel* authName;
    QLineEdit* usernameLE;
    QLineEdit* passwordLE;
    QPushButton* loginButton;
    QLabel* errorLabel;
    QWidget* authForm;
    Client* _client;
private slots:
    void handleAuthorization();
    void onAuthorizationFailed();
signals:
    void sendLoginRequest(const QString& login, const QString& password);
};

#endif // AUTHORIZATION_H
