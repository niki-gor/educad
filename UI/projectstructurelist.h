#ifndef PROJECTSTRUCTURELIST_H
#define PROJECTSTRUCTURELIST_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <vector>

#include <guiobjects.h>

using namespace std;

class ProjectStructureList : public QTreeWidget
{
private:
    QTreeWidgetItem* kingItem;
    QTreeWidget* treeWidget;
    QTreeWidgetItem* planeXYStruct;
    QTreeWidgetItem* planeXZStruct;
    vector <QTreeWidgetItem*> userPlanesStruct;
public:
    QWidget* structureWidget;
    ProjectStructureList();
    int addPointToXYPlaneStructure ();
    int addPointToXZPlaneStructure ();
    int addPointToUserPlaneStructure (GUIPlane plane);
    int addLineToXYPlaneStructure ();
    int addLineToXZPlaneStructure ();
    int addLineToUserPlaneStructure (GUIPlane plane);
    int addNewPlaneToStructure (GUIPlane plane);
};

#endif // PROJECTSTRUCTURELIST_H

