#include <toolbar.h>
#include <QPushButton>
#include "QObject"
#include "QApplication"
//#include "QDesktopWidget"
#include <canvas.h>
#include "QPalette"
#include "QAbstractButton"

ToolBar::ToolBar (QWidget *parent, Canvas* _canvas) {
    parentWidget=parent;
    canvas=_canvas;
    toolBarWidget = new QFrame();
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int scrHeight = 2160*9/10;
    int scrWidth = 3840;
    int butSize = scrHeight*556/10000;
    toolBarWidget->setGeometry(0,0,scrWidth,butSize);
    QPalette pal;
   // pal.setColor(QPalette::Background, Qt::white);
    toolBarWidget->setAutoFillBackground(true);
    toolBarWidget->setPalette(pal);
    toolBarWidget->setFrameShape(QFrame::Box);
    toolBarWidget->setLineWidth(2);
    toolBarWidget->setMidLineWidth(1);
    newProjectButton = new QPushButton("New Project Button", toolBarWidget);
    newProjectButton->setText("New project");
    newProjectButton->setGeometry(QRect(0,0,butSize,butSize));
    saveProjectButton = new QPushButton("Save Project Button", toolBarWidget);
    saveProjectButton->setText("Save project");
    saveProjectButton->setGeometry(QRect(butSize,0,butSize,butSize));
    openProjectButton = new QPushButton("Open Project Button", toolBarWidget);
    openProjectButton->setText("Open project");
    openProjectButton->setGeometry(QRect(2*butSize,0,butSize,butSize));
    createPointButton = new QPushButton("Create Point Button", toolBarWidget);
    createPointButton->setText("Create point");
    createPointButton->setGeometry(QRect(3*butSize,0,butSize,butSize));
    connect(createPointButton, &QPushButton::released, this, &ToolBar::createPointButtonHandler);
    createLineButton = new QPushButton("Create line Button", toolBarWidget);
    createLineButton->setText("Create line");
    createLineButton->setGeometry(QRect(4*butSize,0,butSize,butSize));
    connect(createLineButton, &QPushButton::released, this, &ToolBar::createLineButtonHandler);
    createProjectionPlaneButton = new QPushButton ("Create projection plane Button", toolBarWidget);
    createProjectionPlaneButton->setText("Create projection plane");
    createProjectionPlaneButton->setGeometry(QRect(5*butSize,0,butSize,butSize));
    resizeButton = new QPushButton ("Resize Button", toolBarWidget);
    resizeButton->setText("Resize");
    resizeButton->setGeometry(QRect(6*butSize,0,butSize,butSize));
    eraseButton = new QPushButton ("Erase Button", toolBarWidget);
    eraseButton->setText("Erase");
    eraseButton->setGeometry(QRect(7*butSize,0,butSize,butSize));
    connect(eraseButton, &QPushButton::released, this, &ToolBar::eraseButtonHandler);
}

void ToolBar::newProjectButtonHandler() {};
void ToolBar::saveProjectButtonHandler() {};
void ToolBar::openProjectButtonHander () {};
void ToolBar::createPointButtonHandler () {
    canvas->condition = 1;
    printf ("\ncondition is set to %d\n", canvas->condition);
};
void ToolBar::createLineButtonHandler () {
    canvas->condition = 2;
    printf ("\ncondition is set to %d\n", canvas->condition);
};
void ToolBar::createProjectionPlaneButtonHandler () {};
void ToolBar::resizeButtonHandler() {};
void ToolBar::eraseButtonHandler() {

    printf ("\ncondition is set to clear");
    //canvas->clear();
    canvas->condition=3;
};
