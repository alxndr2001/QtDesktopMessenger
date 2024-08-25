#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtDebug>
#include <QListWidget>
#include <QMainWindow>
#include <QThread>
#include <QStackedWidget>
#include "interface/authorization.h"
#include "interface/chatwindow.h"
#include "interface/chatlist.h"
#include "interface/maininterface.h"
#include "client/client.h"
#include "memory"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private:
    void setDarkTheme();
    Client* client;
    QThread* clithread;
    QStackedWidget* stackedWidget;
    MainInterface* mainInterface;
    Authorization* authInterface;
    Ui::MainWindow *ui;
public slots:
    void onAuthorized(); // Переключение контекста окна после авторизации пользователя
};
#endif // MAINWINDOW_H
