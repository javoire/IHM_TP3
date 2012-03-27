#include "zonededessin.h"

using namespace std;

ZoneDeDessin::ZoneDeDessin(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(500,500);
    newColor = QColor(Qt::black); //default
    newForm = "line"; //default
//    figure.color = QColor(Qt::black); //default
//    figure.form = "line"; //default

    initStateMachine();
}

void ZoneDeDessin::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter painter(this);

    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(255,255,255,255)));

    painter.setRenderHint(QPainter::Antialiasing);

    if (!p1.isNull() && !p2.isNull()) {
        painter.setPen(newColor);

        if (newForm == "line") {
            painter.drawLine(p1, p2);
        } else if (newForm == "rectangle") {
            painter.drawRect(QRect(p1, p2));
        } else if (newForm == "ellipse") {
            painter.drawEllipse(QRect(p1, p2));
        } else if (newForm == "polygon") {

        } else if (newForm == "polyline") {

        }
    }

    if (!formList.isEmpty()) {

        // get shape, color, p1 and p2
        for (int i = 0; i < formList.size(); ++i) {

            painter.setPen(formList[i].color);
            QPoint p1 = formList[i].p1;
            QPoint p2 = formList[i].p2;

//             what shape?
//             better solution??
            if (formList[i].form == "line") {
                painter.drawLine(p1, p2);
            } else if (formList[i].form == "rectangle") {
                painter.drawRect(QRect(p1, p2));
            } else if (formList[i].form == "ellipse") {
                painter.drawEllipse(QRect(p1, p2));
            } else if (formList[i].form == "polygon") {

            } else if (formList[i].form == "polyline") {

            }
        }
    }
 }

void ZoneDeDessin::initStateMachine() {
    QStateMachine * mac = new QStateMachine( );
    QState *s1 = new QState(); //mouse up
    QState *s2 = new QState(); //mouse down

    s2->assignProperty(this, "text", "tja");

    mac->addState(s1);
    mac->addState(s2);
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
}

void ZoneDeDessin::setColor(QColor& color)
{
    newColor = color;
//    update();
}

void ZoneDeDessin::setForm(QString form)
{
    newForm = form;
    cout << "formchanged" << endl;
//    update();
}

void ZoneDeDessin::startDraw()
{

    update();
}

void ZoneDeDessin::drawing()
{

    update();
}

void ZoneDeDessin::endDraw()
{

    // ???
    // QPoint getPos() const { return mapFromGlobal(QCursor::pos());}

    figureStruct newFigure;
    newFigure.color = newColor;
    newFigure.p1 = p1;
    newFigure.p2 = p2;
    newFigure.form = newForm;


    // put shape in list
    formList.append(newFigure);

//    // new painter
//    painterList.append(QPainter::setPen(newColor));

    update();
}

void ZoneDeDessin::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {

        p1 = e->pos();
        p2 = e->pos();
    }
}

void ZoneDeDessin::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {

       update();
    }
}

void ZoneDeDessin::mouseMoveEvent(QMouseEvent* e)
{
    p2 = e->pos();

    update();
}

void ZoneDeDessin::mouseDoubleClickEvent(QMouseEvent* e) {
//    if (e->button() == Qt::LeftButton) {

//        update();
//    }
}


void ZoneDeDessin::deleteAll() {
    if(!formList.isEmpty()) {
        formList.clear();
        p1.setX(0); // set to null
        p1.setY(0);
        p2.setX(0);
        p2.setY(0);
        update();
    }
}

void ZoneDeDessin::deleteLast() {
    if(!formList.isEmpty()) {
        formList.removeLast();
        p1.setX(0);
        p1.setY(0);
        p2.setX(0);
        p2.setY(0);
        update();
    }
}
