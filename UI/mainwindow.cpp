#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlabel.h>
#include <qpicture.h>
#include <qlayout.h>
#include "QDesktopWidget"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    projectStructureList = new ProjectStructureList ();
    canvas = new Canvas(nullptr, this, projectStructureList);
    layout()->addWidget(projectStructureList->structureWidget);
    canvas->move(260,60);
    layout()->addWidget(canvas);
    toolBar = new ToolBar(parent=this, canvas);
    layout()->addWidget(toolBar->toolBarWidget);
    QSize newSize (1920,1080);
    setGeometry(
         QStyle::alignedRect(
             Qt::LeftToRight,
             Qt::AlignCenter,
             newSize,
             qApp->desktop()->availableGeometry()
         )
     );
}

MainWindow::~MainWindow()
{
    delete ui;
}

