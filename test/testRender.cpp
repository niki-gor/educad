//
// Created by Марат Гасанов on 16.04.2022.
//
#include "iostream"
#include "render.h"
#include "gtest/gtest.h"

class GUI:public GUIObserver{
public:
    std::shared_ptr<TwoDEntity> some;
    void onAddToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object)  {
        std::cout << "Added object" << std::endl;
        object->render();
        some = object;
    }

    void onChangeFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object) {
        std::cout << "Object Changed" << std::endl;
        object->render();
    }

    void onDeleteFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object)  {
        std::cout << "Object deleted" << std::endl;
        object->render();
    }
};

TEST(basic, TestOnAddToProjectionPlane){
    std::shared_ptr<Point> point1( new PointByCoords(1, 1, 1));
    std::shared_ptr<Point> point2 (new PointByCoords(2, 2, 2));
    std::shared_ptr<Point> point3 (new PointByCoords(3, 3, 3));

    std::shared_ptr<Line> line1(new LineByTwoPoints(point1, point2));
    std::shared_ptr<Line> line2(new LineByTwoPoints(point2, point3));

    std::shared_ptr<Plane> plane(new PlaneByThreePoints(point1, point2, point3));

    std::shared_ptr<ProjectionPlane> projPlane(new ProjectionPlane(plane));

    Render* render = new Render();
    std::shared_ptr<GUIObserver> gui(new GUI());
    render->observer = gui;
    EXPECT_NO_THROW(render->addToProjectionPlane(projPlane, point1));
}

TEST(basic, TestOnEntityPropagation){
    std::shared_ptr<Point> point1( new PointByCoords(1, 1, 1));
    std::shared_ptr<Point> point2 (new PointByCoords(2, 2, 2));
    std::shared_ptr<Point> point3 (new PointByCoords(3, 3, 3));

    std::shared_ptr<Line> line1(new LineByTwoPoints(point1, point2));
    std::shared_ptr<Line> line2(new LineByTwoPoints(point2, point3));

    std::shared_ptr<Plane> plane(new PlaneByThreePoints(point1, point2, point3));

    std::shared_ptr<ProjectionPlane> projPlane(new ProjectionPlane(plane));

    Render* render = new Render();
    GUI* guiI = new GUI();
    std::shared_ptr<GUIObserver> gui(guiI);
    render->observer = gui;
    render->addToProjectionPlane(projPlane, point1);
    TwoDPoint* poin = dynamic_cast<TwoDPoint*>(&*guiI->some);
    EXPECT_EQ(1, poin->x);
    EXPECT_EQ(2, poin->y);
}

