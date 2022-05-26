#include "projectstructurelist.h"
#include "QString"
#include "string.h"
#include "iostream"
#include "QApplication"
#include "QScreen"
//#include "QDesktopWidget"
#include "QFont"
using namespace std;

ProjectStructureList::ProjectStructureList() {
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int height = rec.height()*9/10;
    int width = rec.width();
    structureWidget = new QFrame ();
    font = QFont("Times", 16);
    treeWidget = new QTreeWidget (structureWidget);
    treeWidget->setFont(font);
    treeWidget->setHeaderLabel("Project Structure");
    setColumnCount(1);
    kingItem = new QTreeWidgetItem();
    kingItem->setFont(0, font);
    planeXYStruct = new QTreeWidgetItem();
    planeXZStruct = new QTreeWidgetItem();
    planeXYStruct->setFont(0,font);
    planeXZStruct->setFont(0, font);
    planeXYStruct->setText(0, "XY Plane");
    planeXZStruct->setText(0, "XZ Plane");
    kingItem->setText(0, "My Project");
    treeWidget->addTopLevelItem(kingItem);
    kingItem->addChild(planeXYStruct);
    kingItem->addChild(planeXZStruct);
    structureWidget->setGeometry(QRect(0,height*556/10000,width/4,height));
    treeWidget->setGeometry(0,0,width/4-2,height);
    treeWidget->setFrameShape(QFrame::NoFrame);
    structureWidget->setFrameShape(QFrame::Box);
    structureWidget->setLineWidth(2);
    structureWidget->setMidLineWidth(1);
}

void ProjectStructureList::clear () {
    for (int i=0; i<planeXYStruct->childCount(); i++) {
          planeXYStruct->removeChild(planeXYStruct->child(i));
    }
    for (int i=0; i<planeXZStruct->childCount(); i++) {
          planeXZStruct->removeChild(planeXZStruct->child(i));
    }
}

int ProjectStructureList::addNewPlaneToStructure() {
    QTreeWidgetItem* newPlaneStruct = new QTreeWidgetItem ();
  //  newPlaneStruct->setText(0, QString::fromStdString(plane.getPlaneName()));
    kingItem->addChild(newPlaneStruct);
    return 0;
}

int ifExistsOnPlane ( QTreeWidgetItem* planeStruct, QString objName, QString objType) {
    for (int i=0; i<planeStruct->childCount(); i++) {
        if (planeStruct->child(i)->text(0).contains(objType + objName)) return i;
    }
    return -1;
}

int ProjectStructureList::addPointToXYPlaneStructure (QString pointName) {
    if (ifExistsOnPlane(planeXYStruct, pointName, "Point ")==-1) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0,"Point " + pointName + "\'");
        planeXYStruct->addChild(newPoint);
        planeXYStruct->child(planeXYStruct->childCount()-1)->setFont(0, font);
    }
    return 0;
}

int ProjectStructureList::addPointToXZPlaneStructure (QString pointName) {
     if (ifExistsOnPlane(planeXZStruct, pointName, "Point ")==-1) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0, "Point " + pointName + "\'\'");
        planeXZStruct->addChild(newPoint);
        planeXZStruct->child(planeXZStruct->childCount()-1)->setFont(0, font);
     }
    return 0;
}

int ProjectStructureList::addLineToXYPlaneStructure (QString lineName) {
    if (ifExistsOnPlane(planeXYStruct, lineName, "Line ")==-1) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0,"Line " + lineName + "\'");
        planeXYStruct->addChild(newPoint);
        planeXYStruct->child(planeXYStruct->childCount()-1)->setFont(0, font);
    }
    return 0;
}

int ProjectStructureList::addLineToXZPlaneStructure (QString lineName) {
     if (ifExistsOnPlane(planeXZStruct, lineName, "Line ")==-1) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0, "Line " + lineName + "\'\'");
        planeXZStruct->addChild(newPoint);
        planeXZStruct->child(planeXZStruct->childCount()-1)->setFont(0, font);
     }
    return 0;
}

int ProjectStructureList::removeLineFromXYPlaneStructure(QString lineName) {
    int index = ifExistsOnPlane(planeXYStruct, lineName, "Line ");
    if (index>=0) {
        QTreeWidgetItem* removableChild = planeXYStruct->child(index);
        planeXYStruct->removeChild(removableChild);
        delete removableChild;
    }
    return 0;
}

int ProjectStructureList::removeLineFromXZPlaneStructure(QString lineName) {
    int index = ifExistsOnPlane(planeXZStruct, lineName, "Line ");
    if (index>=0) {
        QTreeWidgetItem* removableChild = planeXZStruct->child(index);
        planeXZStruct->removeChild(removableChild);
        delete removableChild;
    }
    return 0;
}


int ProjectStructureList::removePointFromXYPlaneStructure(QString pointName) {
    int index = ifExistsOnPlane(planeXYStruct, pointName, "Point ");
    if (index>=0) {
        printf ("point found on XY index=%d\n", index);
        QTreeWidgetItem* removableChild = planeXYStruct->child(index);
        planeXYStruct->removeChild(removableChild);
        delete removableChild;
    }
    return 0;
}

int ProjectStructureList::removePointFromXZPlaneStructure(QString pointName) {
     printf ("\nenterted removing point\n");
    int index = ifExistsOnPlane(planeXZStruct, pointName, "Point ");
    if (index>=0) {
        printf ("point found on XZ index=%d\n", index);
        QTreeWidgetItem* removableChild = planeXZStruct->child(index);
        planeXZStruct->removeChild(removableChild);
        delete removableChild;
    }
    printf ("Finished XZ removing\n");
    return 0;
}








