#include "QtWidgets/QApplication"
#include "mainwindow.h"
//#include "iguiobserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //IGUILineObserver lineObserver (w.canvas);
    //IGUIPointObserver pointObserver (w.canvas);
    w.show();
    return a.exec();
}
