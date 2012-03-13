#include "zonededessin.h"

ZoneDeDessin::ZoneDeDessin(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(500,500);

    initStateMachine();
}

void ZoneDeDessin::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter painter(this);

    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(255,255,255,255)));

    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(newColor);

    painter.drawLine(p1, p2);

}

void ZoneDeDessin::initStateMachine() {
    QStateMachine * mac = new QStateMachine( );
    QState *s1 = new QState(); //mouse up
    QState *s2 = new QState(); //mouse down
    //QState *s3 = new QState();

    s2->assignProperty(this, "text", "tja");

    mac->addState(s1);
    mac->addState(s2);
    //mac->addState(s3);
    mac->setInitialState(s1);
    mac->start();

    addTrans(s1, s2, this, QEvent::MouseButtonPress, Qt::LeftButton);
    addTrans(s2, s2, this, QEvent::MouseMove, Qt::NoButton);
    addTrans(s2, s1, this, QEvent::MouseButtonRelease, Qt::LeftButton);

    connect(s1, SIGNAL(exited()), this, SLOT(startDraw())); // leave mouseup
    connect(s2, SIGNAL(entered()), this, SLOT(drawing())); // enter mousedown
    connect(s1, SIGNAL(entered()), this, SLOT(endDraw())); // enter mouseup
}

void ZoneDeDessin::addTrans(QState* from, QState* to, QObject* object, QEvent::Type type, Qt::MouseButton button)
{
    QMouseEventTransition* trans =  new QMouseEventTransition(object, type, button, from);
    trans->setTargetState(to);
    from->addTransition(trans);
    //from->addTransition(this, signal, to);
}

void ZoneDeDessin::setColor(QColor& color)
{
    newColor = color;

    update();
}

void ZoneDeDessin::startDraw()
{
    cout << "start draw" << endl;

//    if (e->button() == Qt::LeftButton) {

//        p1 = e->pos();
//        p1 = p2;

////        cout << p2.x() << " " << p2.y() << endl;
//    }

    update();
}

void ZoneDeDessin::drawing()
{
    cout << "drawing" << endl;

//    if (e->button() == Qt::LeftButton) {

//        p2 = e->pos();

////        cout << p2.x() << " " << p2.y() << endl;
//    }

    update();
}

void ZoneDeDessin::endDraw()
{
    cout << "end draw" << endl;

    update();
}

void ZoneDeDessin::mousePressEvent(QMouseEvent* e)
{
//    if (e->button() == Qt::LeftButton) {

//        p1 = e->pos();

//        cout << p2.x() << " " << p2.y() << endl;
//    }
}

void ZoneDeDessin::mouseReleaseEvent(QMouseEvent* e)
{
//    if (e->button() == Qt::LeftButton) {

//        p2 = e->pos();

//        cout << p2.x() << " " << p2.y() << endl;
//        update();
//    }
}

void ZoneDeDessin::mouseMoveEvent(QMouseEvent* e)
{
//    if (e->button() == Qt::LeftButton) {

//        update();
//    }
}

void ZoneDeDessin::mouseDoubleClickEvent(QMouseEvent* e) {
//    if (e->button() == Qt::LeftButton) {

//        update();
//    }
}
