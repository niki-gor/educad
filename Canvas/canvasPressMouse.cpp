#include "canvas.h"

void Canvas::mousePressEvent(QMouseEvent *e) {
    QCursor c;
    if (e->button() == Qt::LeftButton) {
        if (condition==0) {
            int index = findInVcp(this->pos.x(), this->pos.y());
            if (index >= 0) {
                if (vcp[index]->isSelected) {
                    vcp[index]->qpColor=Qt::black;
                    selectedObjects.remove(findInSelected(vcp[index]->pos.x(), vcp[index]->pos.y()));
                } else {
                    if (QGuiApplication::keyboardModifiers() & Qt::ShiftModifier) {
                        qp *temp = vcp[index];
                        temp->qpColor = Qt::blue;
                        temp->isSelected = true;
                        selectedObjects.append(temp);
                    } else {
                        if (!selectedObjects.empty()) {
                            for (int i = 0; i < selectedObjects.size(); i++) {
                                selectedObjects[i]->isSelected = false;
                                selectedObjects[i]->qpColor = Qt::black;
                            }
                            selectedObjects.clear();
                        }
                        qp *temp = vcp[index];
                        temp->qpColor = Qt::blue;
                        temp->isSelected = true;
                        selectedObjects.append(temp);
                    }
                }
            } else {
                if (!selectedObjects.empty()) {
                    for (int i = 0; i < selectedObjects.size(); i++) {
                        selectedObjects[i]->isSelected = false;
                        selectedObjects[i]->qpColor = Qt::black;
                    }
                }
                selectedObjects.clear();
                this->update();
            }
        }
        if (condition == 1) {
            if (!blocked) {
                int y;
                if (int i = findInVcp(this->pos.x(), this->pos.y())>=0) {
                    if (vcp[i]->objType==LINE) {
                        qp* line = vcp[i];
                        double renderX = canvasBegin.x() - this->pos.x();
                        double renderY;
                        if (this->pos.y()>height()/2) {
                            renderY = canvasBegin.y() + this->pos.y();
                        } else {
                            renderY = canvasBegin.y() - this->pos.y();
                        }
                        controllerObservable->onCreatePointOn(new double(renderX), new double(renderY), nullptr, line->objectEntity->projectedEntity);
                    }
                } else {
                    qp *qp1 = new qp;
                    qp1->pos = this->pos;
                    qp1->objType = POINT;
                    qp1->qpColor = Qt::red;
                    qp1->needsProjection = false;
                    InputName inputNameWindow;
                    inputNameWindow.exec();
                    qp1->qpName = inputNameWindow.getInput();
                    if (qp1->pos.y() < height() / 2) qp1->planeNumber = 2; else qp1->planeNumber = 1;
                    PTR<ProjectionPlane> plane;
                    if (qp1->planeNumber == 2) {
                        y = qp1->pos.y() - height() / 2;
                    } else {
                        y = qp1->pos.y() + height() / 2;
                    }
                    PTR<TwoDEntity> twoDPoint(new TwoDPoint(qp1->pos.x(), y, plane));
                    qp1->objectEntity = twoDPoint;
                    vcp.append(qp1); //добавили в массив для рисования
                    blocked = true;
                    xBlocked = qp1->pos.x();
                    yBlocked = qp1->planeNumber;
                }
            } else {
                if (xMatch.size() > 0) xMatch.pop_back();
                qp* qp1 = new qp;
                qp1->pos = this->pos;
                qp1->objType = POINT;
                qp1->qpColor = Qt::black;
                qp1->needsProjection = false;
                vcp.back()->qpColor = Qt::black;
                qp1->qpName = vcp.back()->qpName;
                int y, z;
                if (yBlocked == 1) qp1->planeNumber = 2; else qp1->planeNumber = 1;
                PTR <ProjectionPlane> plane;
                PTR<TwoDEntity> twoDPoint;
                if (qp1->planeNumber == 2) {
                    y = vcp.back()->pos.y() - height() / 2;
                    z = height() / 2 - qp1->pos.y();
                    twoDPoint = std::make_shared<TwoDPoint>(qp1->pos.x(), z, plane);
                } else {
                    y = qp1->pos.y() - height() / 2;
                    z = height() / 2 - vcp.back()->pos.y();
                    twoDPoint = std::make_shared<TwoDPoint>(qp1->pos.x(), y, plane);
                }
                qp1->projections.append(vcp.back());
                PTR<Entity> point(new PointByCoords(qp1->pos.x(), y, z));
                vcp.back()->projections.append(qp1);
                twoDPoint->projectedEntity = point;
                qp1->objectEntity=twoDPoint;
                controllerObservable->onAddEntity(point);
                vcp.append(qp1);
                blocked = false;
            }
        }
        if (condition == 2) {
            if ((vcp.size() > 0) && (vcp.last()->needsProjection == true) && (blocked == true)) {
                if (vcp.last()->endpos.x() > 0) {
                    if (xMatch.size() > 0) xMatch.pop_back();
                    qp* qp1 = new qp;
                    qp1->pos = this->pos;
                    qp1->objType = LINE;
                    qp1->qpColor = Qt::red;
                    qp1->qpName = vcp.last()->qpName;
                    if (qp1->pos.y() < height() / 2) qp1->planeNumber = 1; else qp1->planeNumber = 2;
                    qp1->endpos = QPoint(-1, -1);
                    xBlocked = vcp.last()->endpos.x();
                    qp1->needsProjection = true;
                    vcp.append(qp1); //добавили в массив для рисования
                    blocked = true;
                    yBlocked = qp1->planeNumber;
                } else {
                    if (xMatch.size() > 0) xMatch.pop_back();
                    if (help.size() > 0) help.pop_back();
                    qp* qp1 = vcp.back();
                    vcp.pop_back();
                    vcp.back()->qpColor = Qt::black;
                    qp1->endpos = this->pos;
                    qp1->qpColor = Qt::black;
                    if (yBlocked == 1) qp1->planeNumber = 2; else qp1->planeNumber = 1;
                    qp1->projections.append(vcp.back());
                    vcp.back()->projections.append(qp1);
                    PTR <ProjectionPlane> plane;
                    std::tuple lineCoords = linePlaneCoordsToCanvasCoords(qp1);
                    std::tuple lineBegin = std::get<0>(lineCoords);
                    std::tuple lineEnd = std::get<1>(lineCoords);
                    int lineBeginX = std::get<0>(lineBegin); int lineBeginY = std::get<1>(lineBegin); int lineBeginZ = std::get<2>(lineBegin);
                    int lineEndX = std::get<0>(lineEnd); int lineEndY = std::get<1>(lineEnd); int lineEndZ = std::get<2>(lineEnd);
                    PTR<TwoDPoint> twoDLineBegin;
                    PTR<TwoDPoint> twoDLineEnd;
                    if (qp1->planeNumber==1) {
                        twoDLineBegin = std::make_shared<TwoDPoint>(lineBeginX, lineBeginY, plane);
                        twoDLineEnd = std::make_shared<TwoDPoint>(lineEndX, lineEndY, plane);
                    } else {
                        twoDLineBegin = std::make_shared<TwoDPoint>(lineBeginX, lineBeginZ, plane);
                        twoDLineEnd = std::make_shared<TwoDPoint>(lineBeginX, lineBeginZ, plane);
                    }
                    PTR<TwoDEntity> twoDLine (new TwoDLine(twoDLineBegin, twoDLineEnd, plane));
                    PTR<Point> lineBeginPoint (new PointByCoords(lineBeginX, lineBeginY, lineBeginZ));
                    PTR<Point> lineEndPoint (new PointByCoords(lineEndX, lineEndY, lineEndZ));
                    PTR<Entity> line (new LineByTwoPoints(lineBeginPoint, lineEndPoint));
                    twoDLine->projectedEntity = line;
                    qp1->objectEntity=twoDLine;
                    vcp.back()->objectEntity->projectedEntity=line;
                    controllerObservable->onAddEntity(line);
                    vcp.append(qp1);
                    qp1->needsProjection = false;
                    blocked = false;
                }
            } else {
                if (!blocked) {
                    qp* qp1 = new qp;
                    qp1->pos = this->pos;
                    qp1->objType = LINE;
                    qp1->qpColor = Qt::red;
                    InputName inputNameWindow;
                    inputNameWindow.exec();
                    qp1->qpName = inputNameWindow.getInput();
                    if (qp1->pos.y() < height() / 2) qp1->planeNumber = 1; else qp1->planeNumber = 2;
                    qp1->needsProjection = false;
                    qp1->endpos = QPoint(-1, -1);
                    vcp.append(qp1); //добавили в массив для рисования
                    blocked = true;
                    xBlocked = -1;
                    yBlocked = qp1->planeNumber;
                } else {
                    if (help.size() > 0) help.pop_back();
                    qp* qp1 = vcp.back();
                    vcp.pop_back();
                    qp1->endpos = this->pos;
                    if (yBlocked == 1) qp1->planeNumber = 2; else qp1->planeNumber = 1;
                    qp1->needsProjection = true;
                    PTR <ProjectionPlane> plane;
                    int lineBeginX = canvasBegin.x()-qp1->pos.x();
                    int lineEndX = canvasBegin.x()-qp1->endpos.x();
                    PTR<TwoDPoint> twoDLineBegin;
                    PTR<TwoDPoint> twoDLineEnd;
                    int lineBeginY, lineEndY;
                    if (qp1->planeNumber==1) {
                        lineBeginY = qp1->pos.y()-height()/2;
                        lineEndY = qp1->endpos.y()-height()/2;
                    } else {
                        lineBeginY =  height()/2 - qp1->pos.y();
                        lineEndY =  height()/2 - qp1->endpos.y();
                    }
                    twoDLineBegin = std::make_shared<TwoDPoint>(lineBeginX, lineBeginY, plane);
                    twoDLineEnd = std::make_shared<TwoDPoint>(lineEndX, lineEndY, plane);
                    PTR<TwoDEntity> twoDLine (new TwoDLine(twoDLineBegin, twoDLineEnd, plane));
                    qp1->objectEntity=twoDLine;
                    vcp.append(qp1);
                    xBlocked = qp1->pos.x();
                    yBlocked = qp1->planeNumber;
                    blocked = true;
                }
            }
        } else if (condition == 3) {
            int index = findInVcp(this->pos.x(), this->pos.y());
            if (index >= 0) {
                if (vcp[index]->planeNumber == 2) {
                    if (vcp[index]->objType == POINT) {
                        projectStructureList->removePointFromXZPlaneStructure(vcp[index]->qpName);
                    } else if (vcp[index]->objType == LINE) {
                        projectStructureList->removeLineFromXZPlaneStructure(vcp[index]->qpName);
                    }
                } else if (vcp[index]->planeNumber == 1) {
                    if (vcp[index]->objType == POINT) {
                        projectStructureList->removePointFromXYPlaneStructure(vcp[index]->qpName);
                    } else if (vcp[index]->objType == LINE) {
                        projectStructureList->removeLineFromXYPlaneStructure(vcp[index]->qpName);
                    }
                }
                vcp.remove(index);
            }
            rRelated.exec();
            //обновить экран
            this->update();
        }
    }
}

