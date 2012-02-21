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
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawLine(p1, p2);

}

void ZoneDeDessin::mousePressEvent(QMouseEvent* e) {
    if (e->button() == Qt::LeftButton) {

        int x = e->x();
        int y = e->y();

        p1.setX(x);
        p1.setY(y);

        cout << x << " " << y << endl;
    }
}

void ZoneDeDessin::mouseReleaseEvent(QMouseEvent* e) {
    if (e->button() == Qt::LeftButton) {

        int x = e->x();
        int y = e->y();

        p2.setX(x);
        p2.setY(y);

        cout << x << " " << y << endl;
        update();
    }
}

void ZoneDeDessin::mouseMoveEvent(QMouseEvent* e) {
    if (e->button() == Qt::LeftButton) {

        update();
    }
}

void ZoneDeDessin::mouseDoubleClickEvent(QMouseEvent* e) {
    if (e->button() == Qt::LeftButton) {

        update();
    }
}
