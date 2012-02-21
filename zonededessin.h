#ifndef ZONEDEDESSIN_H
#define ZONEDEDESSIN_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>

class ZoneDeDessin : public QWidget
{
Q_OBJECT
public:
    explicit ZoneDeDessin(QWidget *parent = 0);

signals:

public slots:


protected:
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);

};

#endif // ZONEDEDESSIN_H
