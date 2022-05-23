#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include "toolbar.h"
#include <QMouseEvent>
#include "projectstructurelist.h"
#include <contextedit.h>
#include "canvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, PTR<Canvas> = nullptr);
    ~MainWindow();
    void setCanvasCondition (int condition) {canvas->condition=condition;}
    Canvas* canvas;
private:
    Ui::MainWindow *ui;
    ToolBar* toolBar;
    ProjectStructureList* projectStructureList;
    LineContextEdit lineContextEdit;
    PointContextEdit pointContextEdit;
    int f;
};

#endif // MAINWINDOW_H
