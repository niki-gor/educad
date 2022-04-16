#include "mainwindow.h"
#include <QApplication>
#include "guistorage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIStorage selectedObjects;
    GUIStorage objectsOnScreen;
    MainWindow w;
    w.show();
    return a.exec();
}
