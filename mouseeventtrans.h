#ifndef MOUSEEVENTTRANS_H
#define MOUSEEVENTTRANS_H

#include <QMouseEventTransition>
#include <QMouseEvent>
#include <QStateMachine>

using namespace std;

class MouseEventTrans : public QMouseEventTransition
{

    QWidget* canvas; // canvas a une variable currentPos

    public:
        MouseEventTrans(QObject* object, QEvent::Type type, Qt::MouseButton button, QState * srcState)
            : QMouseEventTransition(object, type, button, srcState)
            , canvas(object) { }

        bool eventTest (QEvent * e) {
            if ( ! QMouseEventTransition::eventTest(e) )  return false;  // ne pas oublier cette ligne !

            QStateMachine::WrappedEvent* we = static_cast<QStateMachine::WrappedEvent*>(e);

            QEvent* realEvent = we->event( ); // le vrai événément souris

            switch (realEvent->type( )) {
                case QEvent::MouseMove:
                    canvas->pos() = static_cast<QMouseEvent*>(realEvent)->pos( );  // sauver la position souris

                break;
                    //  .... etc...
            }

            return true;
        }
};

#endif // MOUSEEVENTTRANS_H
