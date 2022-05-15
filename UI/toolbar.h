#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QPushButton>
#include "QMainWindow"
#include "canvas.h"

class ToolBar : public QObject
{
    QPushButton* newProjectButton;
    QPushButton* saveProjectButton;
    QPushButton* openProjectButton;
    QPushButton* createPointButton;
    QPushButton* createLineButton;
    QPushButton* createProjectionPlaneButton;
    QPushButton* resizeButton;
    QPushButton* eraseButton;
    QWidget *parentWidget;
    Canvas* canvas;
public:
    ToolBar(QWidget *parent, Canvas* _canvas);
    QWidget* toolBarWidget;
private slots:
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
