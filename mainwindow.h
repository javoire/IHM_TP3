#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QIcon>
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

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createWidgets();
    QAction* open_action;
    QAction* quit_action;
    QAction* save_action;
    QMenuBar* menubar;
    QMenu* filemenu;
    QToolBar* toolbar;
    QTextEdit* textedit;
    QString filename;
    QString htmlcontent;
    QString outputcontent;
    QMessageBox msgbox;
    ZoneDeDessin* zonedessin;
};

#endif // MAINWINDOW_H
