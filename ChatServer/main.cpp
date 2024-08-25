#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server* server_ = new Server;
    QHostAddress address("127.0.0.1");
    uint16_t port = 1234;
    server_->startServer(address, port);
    return a.exec();
}

