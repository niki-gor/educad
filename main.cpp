#include "QtWidgets/QApplication"
#include "mainwindow.h"
#include "iguiobserver.h"
#include "render.h"
#include "canvas.h"
#include "Controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("../Icons/rk1.png"));
    PTR<GUIAPI> gui(new GUIAPI());
    auto* render = new Render(gui);
    ControllerObservable* controller = new Controller(render);
    auto* projectStructureList = new ProjectStructureList();
    PTR<Canvas> canvas (new Canvas(nullptr, nullptr, projectStructureList, controller));
    gui->canvas=canvas;
    MainWindow* w = new MainWindow(nullptr, canvas);
    canvas->parentWindow = w;
    w->show();
    w->move(0,0);
    return a.exec();
}
