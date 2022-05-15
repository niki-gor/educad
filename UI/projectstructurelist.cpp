#include "projectstructurelist.h"
#include "QString"
#include "string.h"
#include "iostream"
using namespace std;

ProjectStructureList::ProjectStructureList() {
    structureWidget = new QWidget ();
    treeWidget = new QTreeWidget (structureWidget);
    treeWidget->setHeaderLabel("Project Structure");
    setColumnCount(1);
    kingItem = new QTreeWidgetItem();
    planeXYStruct = new QTreeWidgetItem();
    planeXZStruct = new QTreeWidgetItem();
    planeXYStruct->setText(0, "XY Plane");
    planeXZStruct->setText(0, "XZ Plane");
    kingItem->setText(0, "My Project");
    treeWidget->addTopLevelItem(kingItem);
    kingItem->addChild(planeXYStruct);
    kingItem->addChild(planeXZStruct);
    structureWidget->setGeometry(QRect(0,60,480,1040));
}

int ProjectStructureList::addNewPlaneToStructure(GUIPlane plane) {
    QTreeWidgetItem* newPlaneStruct = new QTreeWidgetItem ();
    newPlaneStruct->setText(0, QString::fromStdString(plane.getPlaneName()));
    kingItem->addChild(newPlaneStruct);
    return 0;
}

bool ifExistsOnPlane ( QTreeWidgetItem* planeStruct, QString objName) {
    for (int i=0; i<planeStruct->childCount(); i++) {
        if (planeStruct->child(i)->text(0).contains(objName)) return true;
    }
    return false;
}

int ProjectStructureList::addPointToXYPlaneStructure (QString pointName) {
    if (!ifExistsOnPlane(planeXYStruct, pointName)) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0,"Point " + pointName + "\'");
        planeXYStruct->addChild(newPoint);
    }
    return 0;
}

int ProjectStructureList::addPointToXZPlaneStructure (QString pointName) {
     if (!ifExistsOnPlane(planeXZStruct, pointName)) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0, "Point " + pointName + "\'\'");
        planeXZStruct->addChild(newPoint);
     }
    return 0;
}

