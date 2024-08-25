#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>

#include "maininterface.h"

// Класс обработки отдельно взятого сообщения
class MessageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MessageWidget(const QString& text, bool isSender, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLabel *label;
    bool isSender;
};

#endif // MESSAGEWIDGET_H
