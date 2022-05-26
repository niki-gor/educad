//
// Created by Марат Гасанов on 14.05.2022.
//

#include "gtest/gtest.h"
#include "iostream"
#include "controller.h"
#include "../ControllerObservable/ControllerObservable.h"

PTR<ProjectionPlane> oxy(new ProjectionPlane(0, 0, 1, 0));
PTR<ProjectionPlane> oxz(new ProjectionPlane(1, 0, 0, 0));

class GUI:public GUIObserver{
public:
    std::shared_ptr<TwoDEntity> some;
    void onAddToProjectionPlane(std::shared_ptr<TwoDEntity> object)  {
        object->render();
    }

    void onChangeFromProjectionPlane(std::shared_ptr<TwoDEntity> object) {
        std::cout << "Changed from plane (A = " << object->projectionPlane->getA() << ", B = " << object->projectionPlane->getB() << ", C = " << object->projectionPlane->getC() << ", D = " << object->projectionPlane->getD()  << ")"<< std::endl;
        object->render();
        std::cout << "-----------" << std::endl;
    }

    void onDeleteFromProjectionPlane(std::shared_ptr<TwoDEntity> object)  {
        std::cout << "Deleted from plane (A = " << object->projectionPlane->getA() << ", B = " << object->projectionPlane->getB() << ", C = " << object->projectionPlane->getC() << ", D = " << object->projectionPlane->getD()  << ")"<< std::endl;
        std::cout << "Object deleted" << std::endl;
        object->render();
        std::cout << "-----------" << std::endl;
    }
};

class UI : public Renderable{
    ControllerObservable* controller;
public:
    std::vector<PTR<TwoDEntity>> objectOnScreens;
    void clickMouse(int x, int y, PTR<ProjectionPlane> projectionPlane){
        if (projectionPlane == oxy){
            addPoint(x, y, 0, 0, 1, "point1");
        }
        else{
            addPoint(x, y, 0, 0, 2, "point1");
        }
    }
    void doubleClickMouse(){
        PTR<Point> p1(new PointByCoords(1,1,1));
        PTR<Point> p2(new PointByCoords(2,2,2));
        controller->onAddEntity(PTR<Line>(new LineByTwoPoints(p1, p2)));
    }
public:
    UI(ControllerObservable* co){
        controller = co;
    }

private:
    void addPoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name) override {
        PTR<ProjectionPlane> plane;
        if (planeNumber == 1){
            plane = oxy;
        }
        else{
            plane = oxz;
        }
        PTR<TwoDEntity> point(new TwoDPoint(x, y, plane));
        PTR<Renderable> renderable;
        renderable.reset(this);
        point->setRenderable(renderable);
        objectOnScreens.push_back(point);
    }

    void addLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) override {

    }
};

TEST(basic, Test){
    PTR<GUIObserver> observer(new GUI());
    Render* render = new Render(observer);
    ControllerObservable* controller = new Controller(render);
    UI ui = UI(controller);
    ui.clickMouse(1, 1, oxy);
    ui.clickMouse(1, 1, oxz);
    EXPECT_NO_THROW();
}