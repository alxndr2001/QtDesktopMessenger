#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QHBoxLayout>

class Message : public QWidget
{
    Q_OBJECT
public:
    explicit Message(QWidget *parent, const QString& text, bool isSender);
private:
    const QString& text_;
    QLabel* label;
    bool isSender_;
protected:
    void paintEvent(QPaintEvent *event) override;
signals:

};

#endif // MESSAGE_H
