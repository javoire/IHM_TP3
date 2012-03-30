#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    /* Actions */
    createActions();

    /* Menus */
    createMenus();

    /* Widgets */
    createWidgets();

    //setColor();
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::setColor(QString colorString) {

    if(colorString == "red"){
        cout << "red" << endl;
        color = QColor(Qt::red);
    } else if(colorString == "green") {
        cout << "green" << endl;
        color = QColor(Qt::green);
    } else if(colorString == "blue") {
        cout << "blue" << endl;
        color = QColor(Qt::blue);
    }

    zonedessin->setColor(color);
}

void MainWindow::setForm(QString formString) {
    zonedessin->setForm(formString);
}

void MainWindow::createWidgets()
{
    zonedessin = new ZoneDeDessin(this);
    setCentralWidget(zonedessin);
}

void MainWindow::createMenus()
{
    /* Menu bars */
    menubar = menuBar();
    toolbar = addToolBar(tr("File"));

    filemenu = menubar->addMenu(tr("&File"));
    editmenu = menubar->addMenu(tr("&Actions"));
    colormenu = menubar->addMenu(tr("&Color"));
    formmenu = menubar->addMenu(tr("&Shape"));

    /* Add actions */
    filemenu->addAction(open_action);
    filemenu->addAction(save_action);
    filemenu->addAction(quit_action);

    colormenu->addAction(setColorRed_action);
    colormenu->addAction(setColorBlue_action);
    colormenu->addAction(setColorGreen_action);

    formmenu->addAction(drawLine_action);
    formmenu->addAction(drawRect_action);
    formmenu->addAction(drawEllipse_action);
    formmenu->addAction(drawPolygon_action);
    formmenu->addAction(drawPolyline_action);

    editmenu->addAction(DeleteLast_action);
    editmenu->addAction(DeleteAll_action);

    toolbar->addAction(open_action);
    toolbar->addAction(save_action);
    toolbar->addAction(quit_action);
}

void MainWindow::createActions()
{
    open_action = new QAction(QIcon(":/icons/open.png"), tr("&Open..."), this);
    open_action->setShortcut(tr("Ctrl+N"));
    open_action->setToolTip(tr("Open file"));;
    open_action->setStatusTip(tr("Open file"));

    save_action = new QAction(QIcon(":/icons/save.png"),tr("&Save..."), this);
    save_action->setShortcut(tr("Ctrl+N"));
    save_action->setToolTip(tr("Save file"));;
    save_action->setStatusTip(tr("Save file"));

    quit_action = new QAction(QIcon(":/icons/quit.png"),tr("&Quit..."), this);
    quit_action->setShortcut(tr("Ctrl+N"));
    quit_action->setToolTip(tr("Quit file"));;
    quit_action->setStatusTip(tr("Quit file"));

    // color

    setColorRed_action = new QAction(tr("&Red"), this);
    setColorRed_action ->setToolTip(tr("Change color to red"));;
    setColorRed_action ->setStatusTip(tr("Change color to red"));

    setColorBlue_action = new QAction(tr("&Blue"), this);
    setColorBlue_action->setToolTip(tr("Change color to blue"));;
    setColorBlue_action->setStatusTip(tr("Change color to blue"));

    setColorGreen_action = new QAction(tr("&Green"), this);
    setColorGreen_action->setToolTip(tr("Change color to green"));;
    setColorGreen_action->setStatusTip(tr("Change color to green"));

    // form

    drawLine_action = new QAction(tr("&Line"), this);
    drawLine_action ->setToolTip(tr("Draw a line"));;
    drawLine_action ->setStatusTip(tr("Draw a line"));

    drawRect_action = new QAction(tr("&Rectangle"), this);
    drawRect_action->setToolTip(tr("Draw a rectangle"));;
    drawRect_action->setStatusTip(tr("Draw a rectangle"));

    drawEllipse_action = new QAction(tr("&Ellipse"), this);
    drawEllipse_action->setToolTip(tr("Draw an ellipse"));;
    drawEllipse_action->setStatusTip(tr("Draw an ellipse"));

    drawPolygon_action = new QAction(tr("&Polygon"), this);
    drawPolygon_action->setToolTip(tr("Draw a polygon"));;
    drawPolygon_action->setStatusTip(tr("Draw a polygon"));

    drawPolyline_action = new QAction(tr("&Polyline"), this);
    drawPolyline_action->setToolTip(tr("Draw a polyline"));;
    drawPolyline_action->setStatusTip(tr("Draw a polyline"));

    // delete

    DeleteAll_action = new QAction(tr("&Delete All"), this);
    DeleteAll_action->setToolTip(tr("Delete everything"));;
    DeleteAll_action->setStatusTip(tr("Delete everything"));

    DeleteLast_action = new QAction(tr("&Delete last"), this);
    DeleteLast_action->setToolTip(tr("Delete the most recent element"));;
    DeleteLast_action->setStatusTip(tr("Delete the most recent element"));

    // action group color
    setColor_actionGroup = new QActionGroup(this);
    setColor_actionGroup->addAction(setColorRed_action);
    setColor_actionGroup->addAction(setColorBlue_action);
    setColor_actionGroup->addAction(setColorGreen_action);

    // action group form
    setForm_actionGroup = new QActionGroup(this);
    setForm_actionGroup->addAction(drawLine_action);
    setForm_actionGroup->addAction(drawRect_action);
    setForm_actionGroup->addAction(drawEllipse_action);
    setForm_actionGroup->addAction(drawPolygon_action);
    setForm_actionGroup->addAction(drawPolyline_action);

    // signal mapper color
    signalMapperColor = new QSignalMapper(this);
    signalMapperColor->setMapping(setColorRed_action, QString("red"));
    signalMapperColor->setMapping(setColorGreen_action, QString("green"));
    signalMapperColor->setMapping(setColorBlue_action, QString("blue"));

    // signal mapper form
    signalMapperForm = new QSignalMapper(this);
    signalMapperForm->setMapping(drawLine_action, QString("line"));
    signalMapperForm->setMapping(drawRect_action, QString("rectangle"));
    signalMapperForm->setMapping(drawEllipse_action, QString("ellipse"));
    signalMapperForm->setMapping(drawPolygon_action, QString("polygon"));
    signalMapperForm->setMapping(drawPolyline_action, QString("polyline"));

    // connect slots color
    connect(setColorRed_action, SIGNAL(triggered()), signalMapperColor, SLOT (map()));
    connect(setColorGreen_action, SIGNAL(triggered()), signalMapperColor, SLOT (map()));
    connect(setColorBlue_action, SIGNAL(triggered()), signalMapperColor, SLOT (map()));
    connect(signalMapperColor, SIGNAL(mapped(QString)), this, SLOT(setColor(QString)));

    // connect slots form
    connect(drawLine_action, SIGNAL(triggered()), signalMapperForm, SLOT (map()));
    connect(drawRect_action, SIGNAL(triggered()), signalMapperForm, SLOT (map()));
    connect(drawEllipse_action, SIGNAL(triggered()), signalMapperForm, SLOT (map()));
    connect(drawPolygon_action, SIGNAL(triggered()), signalMapperForm, SLOT (map()));
    connect(drawPolyline_action, SIGNAL(triggered()), signalMapperForm, SLOT (map()));
    connect(signalMapperForm, SIGNAL(mapped(QString)), this, SLOT(setForm(QString)));

    // connect save etc
    connect(open_action, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(save_action, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(quit_action, SIGNAL(triggered()), this, SLOT(quitApp()));

    // delete
    connect(DeleteLast_action, SIGNAL(triggered()), this, SLOT(deleteLast()));
    connect(DeleteAll_action, SIGNAL(triggered()), this, SLOT(deleteAll()));

}

void MainWindow::openFile()
{    
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), ":/", tr("HTML Files (*.html)"));

    /* read file */
    QFile file(filename);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

    /* read contentns */
     QTextStream in(&file);
     htmlcontent = "";
     while (!in.atEnd()) {
        QString line = in.readLine();
        htmlcontent += qPrintable(line);
    }

    /* output to textedit */
    textedit->setHtml(htmlcontent);
}

void MainWindow::saveFile()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save File"), ":/", tr("HTML Files (*.html)"));

    /* read file */
    QFile file(filename);
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

    /* write to file */
    QTextStream out(&file);
    QString outputcontent = textedit->toHtml();
    out << outputcontent;
}

void MainWindow::deleteAll() {
    zonedessin->deleteAll();
}

void MainWindow::deleteLast() {
    zonedessin->deleteLast();
}

void MainWindow::quitApp()
{
    /* messagebox */
    msgbox.setText("Warning!");
    msgbox.setInformativeText("Are you absolutely sure that you wan't to quit? This action can not be undone! Not even by Frodo baggins who simply walked into Mordor!");
    msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgbox.setDefaultButton(QMessageBox::No);
    int ret = msgbox.exec();

    switch (ret) {
      case QMessageBox::Yes:
            exit(0);
          break;
      case QMessageBox::No:
          break;
      default:
          break;
    }
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);

    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
