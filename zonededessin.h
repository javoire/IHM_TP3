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
#include <Qt>
#include <QStateMachine>
#include <QState>
#include <QObject>
//#include <QMouseEventTransition>
#include <mouseeventtrans.h>

using namespace std;

class ZoneDeDessin : public QWidget
{
Q_OBJECT
public:
    explicit ZoneDeDessin(QWidget *parent = 0);

signals:

public slots:
    void setColor(QColor& color);
    void startDraw();
    void drawing();
    void endDraw();
    void initStateMachine();
    void addTrans(QState* from, QState* to, QObject* object, QEvent::Type type, Qt::MouseButton button);

protected:
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);
    QPaintDevice* paintDevice;
    QPainter painter;
    QColor newColor;
    QPoint p1;
    QPoint p2;
//    QMouseEventTransition* trans;
    MouseEventTrans* trans;
    QStateMachine* mac;
    QState* s1;
    QState* s2;
    QState* s3;
    QObject* label;
};

#endif // ZONEDEDESSIN_H
