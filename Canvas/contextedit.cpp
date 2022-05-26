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
    x1=1; y1=1; z1=1; x2=100; y2=100; z2=100;
    PTR<Entity> point1 (new PointByCoords(x1,y1,z1));
    PTR<Entity> point2 (new PointByCoords(x2,y2,z2));
    cnv->getControllerObservable()->onCreateLineByTwoPoint(point1, point2);
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

