#ifndef TOOLBAR_H
#define TOOLBAR_H


#include "QMessageBox"
#include "QDialogButtonBox"
#include <QWidget>
#include <QPushButton>
#include "QMainWindow"
#include "canvas.h"
#include "QObject"

class ToolBar : public QObject
{
   QMessageBox* clearAll;
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
    QFrame* toolBarWidget;
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
