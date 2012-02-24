#ifndef ZONEDEDESSIN_H
#define ZONEDEDESSIN_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QLine>
#include <QPoint>
#include <QBrush>
#include <QDataStream>
#include <iostream>
#include <QColor>

using namespace std;

class ZoneDeDessin : public QWidget
{
Q_OBJECT
public:
    explicit ZoneDeDessin(QWidget *parent = 0);

signals:

public slots:
    void setColor(QColor color);

protected:
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);
    QPaintDevice* paintDevice;
    QPainter painter;
    QBrush bg_brush;
    QPoint p1;
    QPoint p2;

};

#endif // ZONEDEDESSIN_H
