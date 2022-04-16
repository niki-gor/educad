#include <toolbar.h>
#include <QPushButton>


ToolBar::ToolBar () {
    toolBarWidget = new QWidget ();
    newProjectButton = new QPushButton("New Project Button", toolBarWidget);
    newProjectButton->setText("New project");
    newProjectButton->setGeometry(QRect(0,0,60,60));
    saveProjectButton = new QPushButton("Save Project Button", toolBarWidget);
    saveProjectButton->setText("Save project");
    saveProjectButton->setGeometry(QRect(60,0,60,60));
    openProjectButton = new QPushButton("Open Project Button", toolBarWidget);
    openProjectButton->setText("Open project");
    openProjectButton->setGeometry(QRect(120,0,60,60));
    createPointButton = new QPushButton("Create Project Button", toolBarWidget);
    createPointButton->setText("Create point");
    createPointButton->setGeometry(QRect(180,0,60,60));
    createLineButton = new QPushButton("Create line Button", toolBarWidget);
    createLineButton->setText("Create line");
    createLineButton->setGeometry(QRect(240,0,60,60));
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
