#include "message.h"


Message::Message(QWidget *parent, const QString &text, bool isSender) : QWidget(parent),
    text_(text), isSender_(isSender) {
    QLabel *label = new QLabel(text, this);
    label->setWordWrap(true);
    label->setMargin(10);

    QString backgroundColor = isSender ? "#5DADE2" : "#7DCEA0";
    label->setStyleSheet(QString("background-color: %1; border-radius: 15px; color: white;").arg(backgroundColor));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(label);
    layout->setContentsMargins(0, 5, 0, 5);
}

void Message::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    if (isSender_) {
        painter.setBrush(QColor("#43454f"));
    } else {
        painter.setBrush(QColor("#7DCEA0"));
    }

    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawRoundedRect(rect(), 15, 15);
}
