#include "QtWidgets/QApplication"
#include "mainwindow.h"
#include "iguiobserver.h"
#include "render.h"
#include "canvas.h"
#include "Controller/controller.h"

int main(int argc, char *argv[])
{
    PTR<GUIAPI> gui(new GUIAPI());
    auto* render = new Render(gui);
    ControllerObservable* controller = new Controller(render);
    Canvas canvas = Canvas(controller);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
