#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QPushButton>


class ToolBar
{
    QPushButton* newProjectButton;
    QPushButton* saveProjectButton;
    QPushButton* openProjectButton;
    QPushButton* createPointButton;
    QPushButton* createLineButton;
    QPushButton* createProjectionPlaneButton;
    QPushButton* resizeButton;
    QPushButton* eraseButton;
public:
    ToolBar();
    QWidget* toolBarWidget;
    void newProjectButtonHandler();
    void saveProjectButtonHandler();
    void openProjectButtonHander ();
    void createPointButtonHandler ();
    void createLineButtonHandler ();
    void createProjectionPlaneButtonHandler ();
    void resizeButtonHandler();
    void eraseButtonHandler();
};

#endif // TOOLBAR_H
