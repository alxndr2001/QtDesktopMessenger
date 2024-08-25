#include "mainwindow.h"
#include "client/client.h"
#include <QApplication>
#include <QGuiApplication>
#include <QTimer>

#include <QThread>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}

