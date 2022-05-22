#ifndef PROJECTSTRUCTURELIST_H
#define PROJECTSTRUCTURELIST_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <vector>


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
    int addNewPlaneToStructure();
    int addPointToXYPlaneStructure (QString pointName);
    int addPointToXZPlaneStructure (QString pointName);
    int addPointToUserPlaneStructure ();
    int addLineToXYPlaneStructure (QString lineName);
    int addLineToXZPlaneStructure (QString lineName);
    int addLineToUserPlaneStructure ();
    int removePointFromXYPlaneStructure (QString pointName);
    int removePointFromXZPlaneStructure (QString pointName);
    int removePointFromUserPlaneStructure ();
    int removeLineFromXYPlaneStructure (QString lineName);
    int removeLineFromXZPlaneStructure (QString lineName);
    int removeLineFromUserPlaneStructure ();
    int removePlaneFromStructure ();
};

#endif // PROJECTSTRUCTURELIST_H

