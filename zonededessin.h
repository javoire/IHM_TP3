#ifndef ZONEDEDESSIN_H
#define ZONEDEDESSIN_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

class ZoneDeDessin : public QWidget
{
Q_OBJECT
public:
    explicit ZoneDeDessin(QWidget *parent = 0);

signals:

public slots:


protected:
    void paintEvent(QPaintEvent* e);

};

#endif // ZONEDEDESSIN_H
