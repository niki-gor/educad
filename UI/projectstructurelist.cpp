#include "projectstructurelist.h"

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
