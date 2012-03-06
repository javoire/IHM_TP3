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

    setColor();
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::setColor() {
    color = QColor(Qt::red);
    zonedessin->setColor(color);
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

    /* Add actions */
    filemenu->addAction(open_action);
    filemenu->addAction(save_action);
    filemenu->addAction(quit_action);

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

    connect(open_action, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(save_action, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(quit_action, SIGNAL(triggered()), this, SLOT(quitApp()));

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
