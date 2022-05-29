#include "contextedit.h"
#include "qmenu.h"
#include "canvas.h"
#include "../ControllerObservable/ControllerObservable.h"

#include <QPushButton>



void LineContextEdit::handleProjectOnPlaneButton() {

}

void LineContextEdit::handleDrawPerpendicularButton() {

}

void LineContextEdit::handleRenameButton() {

}

void LineContextEdit::handleGetDistanceButton() {

}

void LineContextEdit::handleResizeButton() {

}

void LineContextEdit::handleDeleteButton() {

}

void LineContextEdit::handeCutButton() {

}

void LineContextEdit::handleCopyButton () {

}

void LineContextEdit::handleRealSizeButton() {

}

void LineContextEdit::handlebuildIntersectionButton() {

}

void LineContextEdit::handleBuildParallelLineButton() {

}

void TwoPointsContextEdit::handleLineByTwoPointsButton() {
    printf ("uzbek");
    Canvas* cnv = dynamic_cast<Canvas*>(parent());
    QVector <qp*> pointsToWork = cnv->getSelectedObjects();
    for (int i=0; i<pointsToWork.size(); i++) {
        printf ("%d", pointsToWork[0]->pos.x(),pointsToWork[1]->pos.x());
    }
    int x1,y1,z1,x2,y2,z2;
    std::tuple point1Coords = cnv->pointPlaneCoordsToCanvasCoords(pointsToWork[0]);
    std::tuple point2Coords = cnv->pointPlaneCoordsToCanvasCoords(pointsToWork[1]);
    x1=std::get<0>(point1Coords); y1=std::get<1>(point1Coords); z1=std::get<2>(point1Coords);
    x2=std::get<0>(point2Coords); y2=std::get<1>(point2Coords); z2=std::get<2>(point2Coords);
    printf ("p1x=%d p1y=%d p1z=%d", std::get<0>(point1Coords), std::get<1>(point1Coords),std::get<2>(point1Coords));
    PTR<Entity> point1 (new PointByCoords(x1,y1,z1));
    PTR<Entity> point2 (new PointByCoords(x2,y2,z2));
    cnv->getControllerObservable()->onCreateLineByTwoPoint(point1, point2);
}

void PointAndLineContextEdit::handleParallelLineThroughPointButton () {
    Canvas* cnv = dynamic_cast<Canvas*>(parent());
    QVector <qp*> objectsToWork = cnv->getSelectedObjects();
    //QVector <qp*> selectedObjects = cnv->getSelectedObjects();
    if (objectsToWork[0]->objType==LINE) {
        std::swap(objectsToWork[0], objectsToWork[1]);
    }
    std::tuple pointCoords = cnv->pointPlaneCoordsToCanvasCoords(objectsToWork[0]);
    std::tuple lineCoords = cnv->linePlaneCoordsToCanvasCoords(objectsToWork[1]);
    std::tuple lineBegin = std::get<0>(lineCoords);
    std::tuple lineEnd = std::get<1>(lineCoords);
    int pointX = std::get<0>(pointCoords); int pointY = std::get<1>(pointCoords); int pointZ = std::get<2>(pointCoords);
    int lineBeginX = std::get<0>(lineBegin); int lineBeginY = std::get<1>(lineBegin); int lineBeginZ = std::get<2>(lineBegin);
    int lineEndX = std::get<0>(lineEnd); int lineEndY = std::get<1>(lineEnd); int lineEndZ = std::get<2>(lineEnd);
    PTR<Entity> point (new PointByCoords(pointX, pointY, pointZ));
    PTR<Point> baseLineBegin (new PointByCoords (lineBeginX, lineBeginY, lineBeginZ));
    PTR<Point> baseLineEnd (new PointByCoords (lineEndX, lineEndY, lineEndZ));
    PTR<Entity> baseLine (new LineByTwoPoints(baseLineBegin, baseLineEnd));
    printf ("\n uzbek8=%d tadjik2=%d\n", objectsToWork[0]->objType, objectsToWork[1]->objType);
    cnv->getControllerObservable()->onCreateParallelLine(baseLine, point);
}

LineContextEdit::LineContextEdit() {
    contextEditWidget = new QMenu();
    contextEditWidget->addAction("Спроецировать на плоскость");
    contextEditWidget->addAction("Провести перпендикуляр");
    contextEditWidget->addAction("Переименовать");
    contextEditWidget->addAction("Посчитать дистанцию");
    contextEditWidget->addAction("Изменить размер");
    contextEditWidget->addAction("Удалить");
    contextEditWidget->addAction("Вырезать");
    contextEditWidget->addAction("Скопировать");
    contextEditWidget->addAction("Построить натуральную величину");
    contextEditWidget->addAction("Построить пересечение");
    contextEditWidget->addAction("Построить параллельную прямую");
    connect(&projectOnPlaneButton, SIGNAL (released()), this,SLOT (LineContextEdit::handePprojectOnPlaneButton()));
    connect(&drawPerpendicularButton, SIGNAL (released()), this, SLOT (LineContextEdit::handleDrawPerpendicularLine()));
    connect(&renameButton, SIGNAL (released()), this, SLOT (LineContextEdit::handleRenameButton()));
    connect(&getDistanceButton, SIGNAL (released()), this, SLOT (LineContextEdit::handleGetDistanceButton()));
    connect(&resizeButton, SIGNAL (released()), this, SLOT (LineContextEdit::handleResizeButton()));
    connect(&deleteButton, SIGNAL (released()), this, SLOT (LineContextEdit::handleDeleteButton()));
    connect(&cutButton, SIGNAL (released()), this, SLOT (LineContextEdit::handleCutButton()));
    connect(&copyButton, SIGNAL (released()), this, SLOT (LineContextEdit::handleCopyButton()));
    connect(&deleteButton, SIGNAL (released()), this, SLOT (LineContextEdit::handleRealSizeButton()));
    connect(&cutButton, SIGNAL (released()), this, SLOT (LineContextEdit::handlebuildIntersectionButton()));
    connect(&copyButton, SIGNAL (released()), this, SLOT (LineContextEdit:: handleBuildParallelLineButton()));
}

PointContextEdit::PointContextEdit () {
    contextEditWidget = new QMenu();
    contextEditWidget->addAction("Спроецировать на плоскость");
    contextEditWidget->addAction("Провести перпендикуляр");
    contextEditWidget->addAction("Переименовать");
    contextEditWidget->addAction("Посчитать дистанцию");
    contextEditWidget->addAction("Изменить размер");
    contextEditWidget->addAction("Удалить");
    contextEditWidget->addAction("Вырезать");
    contextEditWidget->addAction("Скопировать");
    connect(&projectOnPlaneButton, SIGNAL (released()), this,SLOT (PointContextEdit::handePprojectOnPlaneButton()));
    connect(&drawPerpendicularButton, SIGNAL (released()), this, SLOT (PointContextEdit::handleDrawPerpendicularLine()));
    connect(&renameButton, SIGNAL (released()), this, SLOT (PointContextEdit::handleRenameButton()));
    connect(&getDistanceButton, SIGNAL (released()), this, SLOT (PointContextEdit::handleGetDistanceButton()));
    connect(&resizeButton, SIGNAL (released()), this, SLOT (PointContextEdit::handleResizeButton()));
    connect(&deleteButton, SIGNAL (released()), this, SLOT (PointContextEdit::handleDeleteButton()));
    connect(&cutButton, SIGNAL (released()), this, SLOT (PointContextEdit::handleCutButton()));
    connect(&copyButton, SIGNAL (released()), this, SLOT (PointContextEdit::handleCopyButton()));
}

TwoPointsContextEdit::TwoPointsContextEdit () {
    twoPointsContextEditWidget = new QMenu ();
    QAction* lineByTwoPointsAction = new QAction(tr("Построить прямую по 2 точкам"), this);
    connect(lineByTwoPointsAction, SIGNAL(triggered()), this, SLOT(handleLineByTwoPointsButton()));
    twoPointsContextEditWidget->addAction(lineByTwoPointsAction);
   // connect(&act, &QPushButton::released, this, &TwoPointsContextEdit::handleLineByTwoPointsButton);
}

DontProjectObjectContextEdit::DontProjectObjectContextEdit() {
    unfinishedPointContextEditWidget = new QMenu();
    QAction* dontProjectAction = new QAction(tr("Не проецировать"), this);
    connect(dontProjectAction, SIGNAL(triggered()), this, SLOT(handleDontProjectButon()));
    unfinishedPointContextEditWidget->addAction(dontProjectAction);
}

PointAndLineContextEdit::PointAndLineContextEdit () {
    pointAndLineContextEditWidget = new QMenu ();
    QAction* paralellLineThroughPointAction = new QAction(tr("Построить параллельную прямую через точку"), this);
    connect(paralellLineThroughPointAction, SIGNAL(triggered()), this, SLOT(handleParallelLineThroughPointButton()));
    pointAndLineContextEditWidget->addAction(paralellLineThroughPointAction);
    QAction* perpendicularFromPointToLineAction = new QAction(tr("Построить перпендикуляр к прямой из точки"), this);
    connect(perpendicularFromPointToLineAction, SIGNAL(triggered()), this, SLOT(handlePerpendicularFromPointToLineButton()));
    pointAndLineContextEditWidget->addAction(perpendicularFromPointToLineAction);
    QAction* planeThroughLineAndPointAction = new QAction(tr("Провести плоскость через прямую и точку"), this);
    connect(planeThroughLineAndPointAction, SIGNAL(triggered()), this, SLOT(handlePlaneThroughLineAndPointButton()));
    pointAndLineContextEditWidget->addAction(planeThroughLineAndPointAction);
    QAction* makeStraightLineAction = new QAction(tr("Провести линию уровня"), this);
    connect(makeStraightLineAction, SIGNAL(triggered()), this, SLOT(handleMakeStraightLine()));
    pointAndLineContextEditWidget->addAction(makeStraightLineAction);
    // connect(&act, &QPushButton::released, this, &TwoPointsContextEdit::handleLineByTwoPointsButton);
}

void PointAndLineContextEdit::handlePerpendicularFromPointToLineButton() {
    Canvas* cnv = dynamic_cast<Canvas*>(parent());
    QVector <qp*> objectsToWork = cnv->getSelectedObjects();
    //QVector <qp*> selectedObjects = cnv->getSelectedObjects();
    if (objectsToWork[0]->objType==LINE) {
        std::swap(objectsToWork[0], objectsToWork[1]);
    }
    std::tuple pointCoords = cnv->pointPlaneCoordsToCanvasCoords(objectsToWork[0]);
    std::tuple lineCoords = cnv->linePlaneCoordsToCanvasCoords(objectsToWork[1]);
    std::tuple lineBegin = std::get<0>(lineCoords);
    std::tuple lineEnd = std::get<1>(lineCoords);
    int pointX = std::get<0>(pointCoords); int pointY = std::get<1>(pointCoords); int pointZ = std::get<2>(pointCoords);
    int lineBeginX = std::get<0>(lineBegin); int lineBeginY = std::get<1>(lineBegin); int lineBeginZ = std::get<2>(lineBegin);
    int lineEndX = std::get<0>(lineEnd); int lineEndY = std::get<1>(lineEnd); int lineEndZ = std::get<2>(lineEnd);
    PTR<Entity> point (new PointByCoords(pointX, pointY, pointZ));
    PTR<Point> baseLineBegin (new PointByCoords (lineBeginX, lineBeginY, lineBeginZ));
    PTR<Point> baseLineEnd (new PointByCoords (lineEndX, lineEndY, lineEndZ));
    PTR<Entity> baseLine (new LineByTwoPoints(baseLineBegin, baseLineEnd));
    cnv->getControllerObservable()->onCreatePerpendicular(point, baseLine);
}

void PointAndLineContextEdit::handlePlaneThroughLineAndPointButton() {
    Canvas* cnv = dynamic_cast<Canvas*>(parent());
    QVector <qp*> objectsToWork = cnv->getSelectedObjects();
    if (objectsToWork[0]->objType==LINE) {
        std::swap(objectsToWork[0], objectsToWork[1]);
    }
    std::tuple pointCoords = cnv->pointPlaneCoordsToCanvasCoords(objectsToWork[0]);
    std::tuple lineCoords = cnv->linePlaneCoordsToCanvasCoords(objectsToWork[1]);
    std::tuple lineBegin = std::get<0>(lineCoords);
    std::tuple lineEnd = std::get<1>(lineCoords);
    int pointX = std::get<0>(pointCoords); int pointY = std::get<1>(pointCoords); int pointZ = std::get<2>(pointCoords);
    int lineBeginX = std::get<0>(lineBegin); int lineBeginY = std::get<1>(lineBegin); int lineBeginZ = std::get<2>(lineBegin);
    int lineEndX = std::get<0>(lineEnd); int lineEndY = std::get<1>(lineEnd); int lineEndZ = std::get<2>(lineEnd);
    PTR<Entity> point (new PointByCoords(pointX, pointY, pointZ));
    PTR<Point> baseLineBegin (new PointByCoords (lineBeginX, lineBeginY, lineBeginZ));
    PTR<Point> baseLineEnd (new PointByCoords (lineEndX, lineEndY, lineEndZ));
    PTR<Entity> baseLine (new LineByTwoPoints(baseLineBegin, baseLineEnd));
    cnv->getControllerObservable()->onDeleteEntity(point);
    cnv->getControllerObservable()->onDeleteEntity(baseLine);
    cnv->getControllerObservable()->onCreatePlaneByLinePoint(baseLine, point);
}

void PointAndLineContextEdit::handleMakeStraightLine() {
    Canvas* cnv = dynamic_cast<Canvas*>(parent());
    QVector <qp*> objectsToWork = cnv->getSelectedObjects();
    if (objectsToWork[0]->objType==LINE) {
        std::swap(objectsToWork[0], objectsToWork[1]);
    }
    int plane;
    if (objectsToWork[0]->planeNumber==1) {
        plane=2;
    } else {
        plane=1;
    }
    cnv->getControllerObservable()->onAddStraightLine(objectsToWork[1]->objectEntity->projectedEntity, objectsToWork[0]->objectEntity->projectedEntity, plane);
}

void PointContextEdit::handleProjectOnPlaneButton() {

}

void PointContextEdit::handleDrawPerpendicularButton() {

}

void PointContextEdit::handleRenameButton() {

}

void PointContextEdit::handleGetDistanceButton() {

}

void PointContextEdit::handleResizeButton() {

}

void PointContextEdit::handleDeleteButton() {

}

void PointContextEdit::handeCutButton() {

}

void PointContextEdit::handleCopyButton () {

}

void DontProjectObjectContextEdit::handleDontProjectButon() {
    Canvas* cnv = dynamic_cast<Canvas*>(parent());
    cnv->unlock();
}

UnprojectedPointContextEdit::UnprojectedPointContextEdit() {
    unprojectedObjectContextEditWidget = new QMenu();
    QAction* connectToPlaneAction = new QAction(tr("Привязать к плоскости"), this);
    connect(connectToPlaneAction, SIGNAL(triggered()), this, SLOT(handleConnectToPlaneButton()));
    unprojectedObjectContextEditWidget->addAction(connectToPlaneAction);
}

void UnprojectedPointContextEdit::handleConnectToPlaneButton() {
    Canvas* cnv = dynamic_cast<Canvas*>(parent());
    qp* pointToWork = cnv->getSelectedObject();
    cnv->condition=4;
    cnv->toWork.append(pointToWork);
}

ConnectedToPlaneContextEdit::ConnectedToPlaneContextEdit() {
    connectedToPlaneContextEditWidget = new QMenu();
    QAction* projectOnPlaneAction = new QAction(tr("Спроецировать на плоскость"), this);
    connect(projectOnPlaneAction, SIGNAL(triggered()), this, SLOT(handleProjectOnPlaneButton()));
    connectedToPlaneContextEditWidget->addAction(projectOnPlaneAction);
}

void ConnectedToPlaneContextEdit::handleProjectOnPlaneButton() {
    Canvas* cnv = dynamic_cast<Canvas*>(parent());
    printf ("pint0 %d", cnv->selectedIndex);
    qp* pointToWork = cnv->getSelectedObject();
    printf ("pint");
    cnv->condition=5;
    cnv->toWork.append(pointToWork);
}