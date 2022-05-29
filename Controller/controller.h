//
// Created by Марат Гасанов on 13.05.2022.
//

#ifndef EDUCAD_CONTROLLER_H
#define EDUCAD_CONTROLLER_H
#include "render.h"
#include "AngemModelWorker.hpp"
#include "../ControllerObservable/ControllerObservable.h"
#include "Angem.hpp"
#include "../AlgoInterface/AlgoInterface.h"

class Controller: public ControllerObservable{
private:
//    AngemModelWorker* worker;
    void addToModel(PTR<Entity> entity);
    void renderEntity(PTR<Entity> entity);
    void disRenderEntity(PTR<Entity> entity);
    Render* render;
    PTR<ProjectionPlane> oxy;
    PTR<ProjectionPlane> oxz;
    AlgoInterface* algo;
public:
    bool onCreateLineByTwoPoint(PTR<Entity> point1, PTR<Entity> point2) override;

    bool onCreatePerpendicular(PTR<Entity> point, PTR<Entity> line) override;

    bool onCreateParallelLine(PTR<Entity> line, PTR<Entity> point) override;

    Controller(Render* render, AlgoInterface* algoI);
    PTR<Entity> onAddEntity(PTR<Entity> entity) override;
    void onDeleteEntity(PTR<Entity> entity) override;

    bool onCreatePointOn(double* x, double * y, double * z, PTR<Entity> line) override;

    bool onCreatePlaneByThreePoints(PTR<Entity> point1, PTR<Entity> point2, PTR<Entity> point3) override;

    bool onCreatePlaneByParallels(PTR<Entity> line1, PTR<Entity> line2) override;

    bool onCreatePlaneByIntersecting(PTR<Entity> line1, PTR<Entity> line2) override;

    bool onCreatePlaneByLinePoint(PTR<Entity> line, PTR<Entity> point) override;

    bool onAddPointOnPlaneProjectionAlgo(PTR<Entity> plane, PTR<Entity> point) override;

    PTR<Entity> onLinkToPlane(double *x, double *y, double *z, PTR<Entity> plane) override;


    void runAlgorithm(algorithm<TwoDEntity> alg);

    bool onAddStraightLine(PTR<Entity> line, PTR<Entity> point, int projectionPlane) override;
};

#endif //EDUCAD_CONTROLLER_H
