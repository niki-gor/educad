#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include "QPushButton"
#include <QPen>
#include "QDialog"
#include "QLineEdit"
#include "QMainWindow"
#include "projectstructurelist.h"
#include "QMessageBox"
#include "contextedit.h"
#include "../ControllerObservable/ControllerObservable.h"
#include "Renderable.h"
#include "QApplication"
#include "QPicture"
#include "QBrush"
#include "QBoxLayout"
#include "QPushButton"
#include "QCursor"
#include "QPainterPath"
#include "QMenu"
#include "QApplication"
#include "utils.h"
#include "Entity.hpp"
#include <memory>
#include <tuple>


class InputName : public QDialog {
    Q_OBJECT
public:
    InputName( QWidget* parent = nullptr );
    ~InputName() {}
    QString getInput() const {return m_edit->text();}
signals:
    void applied();
private:
    QLineEdit* m_edit;
};

class removeRelated : public QMessageBox {
    Q_OBJECT
public:
    removeRelated( QWidget* parent = nullptr );
    ~removeRelated() {}
signals:
    void applied();
private:
    QPushButton* YESButton;
    QPushButton* NOButton;
};

enum ObjectType {
    POINT=0,
    LINE=1,
    NOTHING=2,
    PLANEBYLINEANDPOINT=3
};

struct qp //структура для хранения координаты при рисовании
{
    PTR<TwoDEntity> objectEntity;
    QPoint pos;
    QPoint endpos;
    QPoint pos2;
    QPoint endpos2;
    ObjectType objType;
    QColor qpColor;
    QString qpName;
    bool needsProjection;
    int planeNumber;
    bool isSelected=false;
    bool connectedToPlane = false;
    QVector<qp*> projections;
};

class Canvas : public QWidget, public Renderable
{
    Q_OBJECT
public:
    QVector <qp*> toWork;
    void clear();
    Canvas(QWidget* parent = nullptr, QMainWindow* _parent=nullptr, ProjectStructureList* _projectStructureList=nullptr, ControllerObservable* controllerObservable= nullptr);
    void prepareCanvas ();
    int condition; //0=dead 1=point 2=line
    void addPoint (int x, int y, int xBegin, int yBegin, int planeNumber, std::string name, TwoDPoint* twoDEntity);
    void addLine (int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name);
    ProjectStructureList* getProjectStructureList () {return projectStructureList;}
    QMainWindow* parentWindow;
    QVector<qp*> getSelectedObjects () {return selectedObjects;}
    ControllerObservable* getControllerObservable () {return controllerObservable;}
    std::tuple<int, int> canvasCoordsToPlaneCoords (int x, int y, PTR<ProjectionPlane>);
    std::tuple<int,int,int> pointPlaneCoordsToCanvasCoords (qp *object);
    std::tuple<std::tuple<int,int,int>,std::tuple<int,int,int>> linePlaneCoordsToCanvasCoords (qp* object);
    void deletePoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name);
    void deleteLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name);
    void unlock() {blocked= false; xMatch.remove(0); this->update();}
    qp* getSelectedObject () {return vcp[selectedIndex];};
    int selectedIndex;
    void addPlaneByLineAndPoint (int x, int y, int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name, TwoDEntity* twoDEntity);

    void addLinkLine(PTR<TwoDEntity> entity1, PTR<TwoDEntity> entity2) override;

private:
    qp* findInVcpByPTR (PTR<TwoDEntity> entity);
    ConnectedToPlaneContextEdit connectedPointRMB;
    UnprojectedPointContextEdit unprojectedPointRMB;
    PointAndLineContextEdit pointAndLineRMB;
    DontProjectObjectContextEdit oneProjectionRMB;
    QPoint canvasBegin;
    TwoPointsContextEdit twoPointsRMB;
    int findInSelected (int x, int y);
    ControllerObservable* controllerObservable;
    LineContextEdit lineRMB;
    PointContextEdit pointRMB;
    int findInVcp (int x, int y);
    void paintEvent(QPaintEvent *event);
    QPoint pos; //координаты точки для рисования
    void mouseMoveEvent(QMouseEvent *event);
    removeRelated rRelated;
    QVector<qp*> vcp; //массив (вектор) для хранения рисунка
    QVector<qp*> selectedObjects;
    QVector<qp> help; //массив (вектор) для хранения рисунка
    QVector<qp> xMatch; //массив (вектор) для хранения рисунка
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    int f;
    bool blocked=false;
    ObjectType selected;
    QPainter p;
    QPen pen;
    int xBlocked;
    int yBlocked;
    ProjectStructureList* projectStructureList;
signals:
};

#endif // CANVAS_H
