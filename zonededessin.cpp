#include "zonededessin.h"

using namespace std;

ZoneDeDessin::ZoneDeDessin(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(500,500);
    newColor = QColor(Qt::black); //default
    newShape = "line"; //default
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

    if (!drawPoints.empty()) {
        painter.setPen(newColor);

        QPoint p1 = drawPoints[0];
        QPoint p2 = drawPoints[1];

        if (newShape == "line") {
            painter.drawLine(p1, p2);
        } else if (newShape == "rectangle") {
            painter.drawRect(QRect(p1, p2));
        } else if (newShape == "ellipse") {
            painter.drawEllipse(QRect(p1, p2));
        } else if (newShape == "polygon") {
            painter.drawPolygon(QPolygon(drawPoints));
        } else if (newShape == "polyline") {

        }

    }

    if (!formList.isEmpty()) {

        // get shape, color, p1 and p2
        for (int i = 0; i < formList.size(); ++i) {

            painter.setPen(formList[i].color);
            QPoint p1 = formList[i].points[0];
            QPoint p2 = formList[i].points[1];

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
    newShape = form;
    cout << "formchanged" << endl;
//    update();
}

void ZoneDeDessin::startDraw()
{
    if ( newShape == "polygon" ) {
        this->setMouseTracking(true); // we will lift the mousebutton to create new points...
    } else {
        this->setMouseTracking(false);
    }
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

    if (!drawPoints.empty()) {
        newFigure.color = newColor;
        newFigure.points.append(drawPoints[0]);
        newFigure.points.append(drawPoints[1]);
        newFigure.form = newShape;

        // put shape in list
        formList.append(newFigure);
    }

    update();
}

void ZoneDeDessin::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {

        drawPoints.append(e->pos());
        drawPoints.append(e->pos());
    }
}

void ZoneDeDessin::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {

       update();
       drawPoints.clear(); // always empty after drawing
    }
}

void ZoneDeDessin::mouseMoveEvent(QMouseEvent* e)
{
    drawPoints[1] = e->pos();

    if ( newShape == "polygon" ) {
        cout << e->x() << ":" << e->y() << endl;
    }

    update();
}

void ZoneDeDessin::mouseDoubleClickEvent(QMouseEvent* e) {

    // end draw polygon!!

//    if (e->button() == Qt::LeftButton) {

//        update();
//    }
}


void ZoneDeDessin::deleteAll() {
    if(!formList.isEmpty()) {
        formList.clear();
        drawPoints.clear();
        update();
    }
}

void ZoneDeDessin::deleteLast() {
    if(!formList.isEmpty()) {
        formList.removeLast();
        drawPoints.clear();
        update();
    }
}
