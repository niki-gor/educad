#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "toolbar.h"
#include "projectstructurelist.h"
#include "descriptive.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ToolBar* toolBar;
    ProjectStructureList* projectStructureList;
    DescriptiveSpace* descriptiveSpace;
};

#endif // MAINWINDOW_H
