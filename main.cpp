#include "QtWidgets/QApplication"
#include "mainwindow.h"
#include "controller.h"
#include "canvas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //IGUILineObserver lineObserver (w.canvas);
    //IGUIPointObserver pointObserver (w.canvas);
    MainWindow w;
    w.show();
    return a.exec();
}
