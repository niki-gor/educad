#include "contextedit.h"
#include "qmenu.h"

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