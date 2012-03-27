#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QIcon>
#include <QEvent>
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QString>
#include <iostream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QColor>
#include <QSignalMapper>
#include <zonededessin.h>

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void openFile();
    void saveFile();
    void quitApp();
    void deleteLast();
    void deleteAll();
    void setColor(QString colorString);
    void setForm(QString formString);

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createWidgets();
    QAction* setColorRed_action;
    QAction* setColorGreen_action;
    QAction* setColorBlue_action;
    QAction* open_action;
    QAction* save_action;
    QAction* quit_action;
    QAction* DeleteLast_action;
    QAction* DeleteAll_action;
    QAction* drawLine_action;
    QAction* drawRect_action;
    QAction* drawEllipse_action;
    QAction* drawPolygon_action;
    QAction* drawPolyline_action;
    QActionGroup* setColor_actionGroup;
    QActionGroup* setForm_actionGroup;
    QMenuBar* menubar;
    QMenu* filemenu;
    QMenu* colormenu;
    QMenu* editmenu;
    QMenu* formmenu;
    QToolBar* toolbar;
    QTextEdit* textedit;
    QString filename;
    QString htmlcontent;
    QString outputcontent;
    QMessageBox msgbox;
    ZoneDeDessin* zonedessin;
    QColor color;
    QString form;
    QSignalMapper* signalMapperColor;
    QSignalMapper* signalMapperForm;
};

#endif // MAINWINDOW_H
