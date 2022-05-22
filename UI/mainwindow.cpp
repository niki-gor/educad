#include <qlabel.h>
#include <qpicture.h>
#include <qlayout.h>
#include "QGuiApplication"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "QDesktopWidget"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    projectStructureList = new ProjectStructureList ();
    canvas = new Canvas(nullptr, this, projectStructureList);
    layout()->addWidget(projectStructureList->structureWidget);
    layout()->addWidget(canvas);
    toolBar = new ToolBar(parent=this, canvas);
    layout()->addWidget(toolBar->toolBarWidget);
    setWindowTitle("EDUCAD");
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int scrHeight = rec.height()*9/10;
    int scrWidth = rec.width();
    printf ("%d %d", scrHeight ,scrWidth/4);
    QSize newSize (scrWidth,scrHeight);
    this->resize(newSize);
    int canvX = scrWidth / 4;
    int canvY = scrHeight * 555 / 10000;
    canvas->move(canvX, canvY);
    QPalette pal;
  //  pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    setGeometry(
         QStyle::alignedRect(
             Qt::LeftToRight,
             Qt::AlignCenter,
             newSize,
             qApp->primaryScreen()->availableGeometry()
         )
     );
}

MainWindow::~MainWindow()
{
    delete ui;
}

