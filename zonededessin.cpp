#include "zonededessin.h"

ZoneDeDessin::ZoneDeDessin(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(500,500);

}

void ZoneDeDessin::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter painter(this);
    painter.drawLine(50,100,100,50);
}

void ZoneDeDessin::mousePressEvent(QMouseEvent* e) {

}

void ZoneDeDessin::mouseReleaseEvent(QMouseEvent* e) {

}

void ZoneDeDessin::mouseMoveEvent(QMouseEvent* e) {

}

void ZoneDeDessin::mouseDoubleClickEvent(QMouseEvent* e) {

}
