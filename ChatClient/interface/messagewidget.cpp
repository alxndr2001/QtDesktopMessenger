#include "messagewidget.h"

MessageWidget::MessageWidget(const QString &text, bool isSender, QWidget *parent)
    : QWidget(parent), isSender(isSender) {

    label = new QLabel(text, this);
    label->setWordWrap(true);
    label->setMargin(10);

    label->setMaximumWidth(100);
    label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);

    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);
    label->setPalette(palette);

    if (isSender) {
        label->setStyleSheet("background-color: #5DADE2; border-radius: 15px;");
    } else {
        label->setStyleSheet("background-color: #7DCEA0; border-radius: 15px;");
    }

    QHBoxLayout *messageLayout = new QHBoxLayout();
    if (isSender) {
        messageLayout->addStretch();
        messageLayout->addWidget(label);
    } else {
        messageLayout->addWidget(label);
        messageLayout->addStretch();
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->addLayout(messageLayout);

    setLayout(mainLayout);
}

void MessageWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    if (isSender) {
        painter.setBrush(QColor("#5DADE2"));
    } else {
        painter.setBrush(QColor("#7DCEA0"));
    }

    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawRoundedRect(rect(), 15, 15);
}
