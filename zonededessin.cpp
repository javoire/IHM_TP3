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

    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(255,255,255,255)));

    bg_brush.setStyle(Qt::SolidPattern);
    bg_brush.setColor(Qt::white);

    painter.setPen(Qt::red);

    painter.drawLine(p1, p2);

}

void ZoneDeDessin::setColor(QColor color)
{
    //painter.setPen(Qt::red);

    update();
}

void ZoneDeDessin::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {

        p1 = e->pos();

        cout << p2.x() << " " << p2.y() << endl;
    }
}

void ZoneDeDessin::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {

        p2 = e->pos();

        cout << p2.x() << " " << p2.y() << endl;
        update();
    }
}

void ZoneDeDessin::mouseMoveEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {

        //p2 = e->pos();

        //cout << p2.x() << " " << p2.y() << endl;
        update();
    }
}

void ZoneDeDessin::mouseDoubleClickEvent(QMouseEvent* e) {
    if (e->button() == Qt::LeftButton) {

        update();
    }
}
