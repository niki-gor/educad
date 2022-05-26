#include <qlabel.h>
#include <qlayout.h>
#include "QGuiApplication"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, PTR<Canvas> _canvas) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = _canvas.get();
    projectStructureList = canvas->getProjectStructureList();
    layout()->addWidget(projectStructureList->structureWidget);
    layout()->addWidget(canvas);
    toolBar = new ToolBar(parent=this, canvas);
    layout()->addWidget(toolBar->toolBarWidget);
    setWindowTitle("EDUCAD");
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int scrHeight = QGuiApplication::primaryScreen()->availableGeometry().height();
    int scrWidth = QGuiApplication::primaryScreen()->availableGeometry().width();
    printf ("%d %d", scrHeight ,scrWidth/4);
    QSize newSize (scrWidth,scrHeight);
    this->resize(newSize);
    int canvX = scrWidth / 4;
    int canvY = scrHeight * 556 / 10000;
    canvas->move(canvX, canvY);
    QPalette pal;
    pal.setColor(QPalette::Window, QColor(255, 255, 255));
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

