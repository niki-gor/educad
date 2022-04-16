#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qlayout.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPainter painter;
    ui->setupUi(this);
    projectStructureList = new ProjectStructureList ();
    toolBar = new ToolBar();
    descriptiveSpace = new DescriptiveSpace();
    layout()->addWidget(toolBar->toolBarWidget);
    layout()->addWidget(projectStructureList->structureWidget);
    painter.drawImage(QPoint(340,60), descriptiveSpace->getXYIm());
    painter.drawImage(QPoint(340,660), descriptiveSpace->getXZIm());
}

MainWindow::~MainWindow()
{
    delete ui;
}
