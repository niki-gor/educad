//
// Created by Марат Гасанов on 16.04.2022.
//
#include "iostream"
#include "render.h"
#include "gtest/gtest.h"

//Global MatModel
std::shared_ptr<Point> point1( new PointByCoords(1, 0, 0));
std::shared_ptr<Point> point2 (new PointByCoords(2, 2, 2));
std::shared_ptr<Point> point3 (new PointByCoords(3, 3, 3));

std::shared_ptr<Line> line1(new LineByTwoPoints(point1, point2));
std::shared_ptr<Line> line2(new LineByTwoPoints(point2, point3));

std::shared_ptr<Plane> planeByPoints(new PlaneByThreePoints(point1, point2, point3));
std::shared_ptr<ProjectionPlane> projPlane(new ProjectionPlane(planeByPoints));

class GUI:public GUIObserver{
public:
    std::shared_ptr<TwoDEntity> some;
    void onAddToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object)  {
        std::cout << "Added object to plane (A = " << plane->getA() << ", B = " << plane->getB() << ", C = " << plane->getC() << ", D = " << plane->getD()  << ")"<< std::endl;
        object->render();
        std::cout << "-----------" << std::endl;
        some = object;
    }

    void onChangeFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object) {
        std::cout << "Changed from plane (A = " << plane->getA() << ", B = " << plane->getB() << ", C = " << plane->getC() << ", D = " << plane->getD()  << ")"<< std::endl;
        object->render();
        std::cout << "-----------" << std::endl;
    }

    void onDeleteFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object)  {
        std::cout << "Deleted from plane (A = " << plane->getA() << ", B = " << plane->getB() << ", C = " << plane->getC() << ", D = " << plane->getD()  << ")"<< std::endl;
        std::cout << "Object deleted" << std::endl;
        object->render();
        std::cout << "-----------" << std::endl;
    }
};

TEST(basic, TestOnAddToProjectionPlane){

    Render* render = new Render();
    std::shared_ptr<GUIObserver> gui(new GUI());
    render->observer = gui;
    EXPECT_NO_THROW(render->addToProjectionPlane(projPlane, point1));
}

TEST(basic, TestOnEntityPropagation){
    Render* render = new Render();
    GUI* guiI = new GUI();
    std::shared_ptr<GUIObserver> gui(guiI);
    render->observer = gui;
    render->addToProjectionPlane(projPlane, point1);
    TwoDPoint* poin = dynamic_cast<TwoDPoint*>(&*guiI->some);
    EXPECT_EQ(1, poin->X);
    EXPECT_EQ(2, poin->Y);
}

