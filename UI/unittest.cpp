/*#include <QtTest/QTest>
#include <unittest.h>
#include "canvas.h"
#include "contextedit.h"
#include "controller.h"
#include "guiobjects.h"
#include "toolbar.h"
#include "mainwindow.h"
//#include "../Entity/Entity.hpp"

UnitTest::UnitTest() {

}

void UnitTest::testCanvas () {
    Canvas canvas;
   // canvas.createImage(100, 100);
    canvas.paintEngine();
}

void UnitTest::testContextEdit() {
    LineContextEdit lineContextEdit;
    PointContextEdit pointContextEdit;
    pointContextEdit.handeCutButton();
    pointContextEdit.handleCopyButton();
    pointContextEdit.handleDeleteButton();
    pointContextEdit.handleRenameButton();
    pointContextEdit.handleResizeButton();
    pointContextEdit.handleGetDistanceButton();
    pointContextEdit.handleProjectOnPlaneButton();
    pointContextEdit.handleDrawPerpendicularButton();
    lineContextEdit.handeCutButton();
    lineContextEdit.handleCopyButton();
    lineContextEdit.handleDeleteButton();
    lineContextEdit.handleRenameButton();
    lineContextEdit.handleResizeButton();
    lineContextEdit.handleGetDistanceButton();
    lineContextEdit.handleProjectOnPlaneButton();
    lineContextEdit.handleDrawPerpendicularButton();
    lineContextEdit.handlebuildIntersectionButton();
    lineContextEdit.handleRealSizeButton();
    lineContextEdit.handleBuildParallelLineButton();
}

void UnitTest::testController() {
    //Controller controller(ProjectionPlane(<#initializer#>));
  //  controller.onButtonPress();
 //   controller.onRMBClick();
    //controller.onLMBClick();
}

void UnitTest::testGUIObjects() {
    GUIPoint point;
    GUIAxis axis;
    GUIPlane plane;
    GUILine line;
    QVERIFY(line.draw()==0);
    QVERIFY(point.draw()==0);
    QVERIFY(plane.draw()==0);

    QVERIFY(line.reDraw()==0);
    QVERIFY(point.reDraw()==0);
    QVERIFY(plane.reDraw()==0);

    QVERIFY(line.remove()==0);
    QVERIFY(point.remove()==0);
    QVERIFY(plane.remove()==0);
}

void UnitTest::testToolbar() {
   // ToolBar toolBar;
   // toolBar.eraseButtonHandler();
   // toolBar.resizeButtonHandler();
  //  toolBar.createLineButtonHandler();
 //   toolBar.newProjectButtonHandler();
  //  toolBar.openProjectButtonHander();
 //   toolBar.createPointButtonHandler();
  //  toolBar.saveProjectButtonHandler();
 //   toolBar.createProjectionPlaneButtonHandler();
}

void UnitTest::testGUIObservers() {

}

int main(int argc, char *argv[]) {
    UnitTest test;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
 //   test.testCanvas();
 //   test.testToolbar();
 //   test.testController();
 //   test.testGUIObjects();
 //   test.testContextEdit();
    return a.exec();
}*/
