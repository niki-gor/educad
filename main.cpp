#include "QtWidgets/QApplication"
#include "mainwindow.h"
#include "iguiobserver.h"
#include "render.h"
#include "canvas.h"
#include "Controller/controller.h"
#include "controller.h"
#include "canvas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PTR<GUIAPI> gui(new GUIAPI());
    auto* render = new Render(gui);
    ControllerObservable* controller = new Controller(render);
    ProjectStructureList* projectStructureList;
    PTR<Canvas> canvas (new Canvas(nullptr, nullptr, projectStructureList, controller));
    gui->canvas=canvas;
    MainWindow w (nullptr, canvas);
    w.show();
    return a.exec();
}
