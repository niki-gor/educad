#include <toolbar.h>
#include <QPushButton>
#include "QObject"
#include <canvas.h>

ToolBar::ToolBar (QWidget *parent, Canvas* _canvas) {
    parentWidget=parent;
    canvas=_canvas;
    toolBarWidget = new QWidget ();
    toolBarWidget->setGeometry(0,0,480,60);
    newProjectButton = new QPushButton("New Project Button", toolBarWidget);
    newProjectButton->setText("New project");
    newProjectButton->setGeometry(QRect(0,0,60,60));
    saveProjectButton = new QPushButton("Save Project Button", toolBarWidget);
    saveProjectButton->setText("Save project");
    saveProjectButton->setGeometry(QRect(60,0,60,60));
    openProjectButton = new QPushButton("Open Project Button", toolBarWidget);
    openProjectButton->setText("Open project");
    openProjectButton->setGeometry(QRect(120,0,60,60));
    createPointButton = new QPushButton("Create Point Button", toolBarWidget);
    createPointButton->setText("Create point");
    createPointButton->setGeometry(QRect(180,0,60,60));
    connect(createPointButton, &QPushButton::released, this, &ToolBar::createPointButtonHandler);
    createLineButton = new QPushButton("Create line Button", toolBarWidget);
    createLineButton->setText("Create line");
    createLineButton->setGeometry(QRect(240,0,60,60));
    connect(createLineButton, &QPushButton::released, this, &ToolBar::createLineButtonHandler);
    createProjectionPlaneButton = new QPushButton ("Create projection plane Button", toolBarWidget);
    createProjectionPlaneButton->setText("Create projection plane");
    createProjectionPlaneButton->setGeometry(QRect(300,0,60,60));
    resizeButton = new QPushButton ("Resize Button", toolBarWidget);
    resizeButton->setText("Resize");
    resizeButton->setGeometry(QRect(360,0,60,60));
    eraseButton = new QPushButton ("Erase Button", toolBarWidget);
    eraseButton->setText("Erase");
    eraseButton->setGeometry(QRect(420,0,60,60));
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
void ToolBar::eraseButtonHandler() {};
