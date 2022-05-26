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
    QFont font;
public:
    QFrame* structureWidget;
    void clear ();
    ProjectStructureList();
    int addNewPlaneToStructure(GUIPlane plane);
    int addPointToXYPlaneStructure (QString pointName);
    int addPointToXZPlaneStructure (QString pointName);
    int addPointToUserPlaneStructure (GUIPlane plane);
    int addLineToXYPlaneStructure (QString lineName);
    int addLineToXZPlaneStructure (QString lineName);
    int addLineToUserPlaneStructure (GUIPlane plane);
    int removePointFromXYPlaneStructure (QString pointName);
    int removePointFromXZPlaneStructure (QString pointName);
    int removePointFromUserPlaneStructure (GUIPlane plane);
    int removeLineFromXYPlaneStructure (QString lineName);
    int removeLineFromXZPlaneStructure (QString lineName);
    int removeLineFromUserPlaneStructure (GUIPlane plane);
    int removePlaneFromStructure (GUIPlane plane);
};

#endif // PROJECTSTRUCTURELIST_H

