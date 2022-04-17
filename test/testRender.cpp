//
// Created by Марат Гасанов on 16.04.2022.
//
#include "iostream"
#include "render.h"
#include "gtest/gtest.h"

class GUI:GUIObserver{
    void onAddToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object) override {
        std::cout << "Get Back Motherfuck" << std::endl;
    }

    void onChangeFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> oldObject,
                                     std::shared_ptr<TwoDEntity> newObject) override {

    }

    void
    onDeleteFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object) override {

    }
};

std::shared_ptr<Point> point1 = new PointByCoords(1, 1, 1);
std::shared_ptr<Point> point2 = new PointByCoords(2, 2, 2);
std::shared_ptr<Point> point3 = new PointByCoords(3, 3, 3);

std::shared_ptr<Line> line1 = new LineByTwoPoints(point1, point2);
std::shared_ptr<Line> line2 = new LineByTwoPoints(point2, point3);

std::shared_ptr<ProjectionPlane> projPlane = new ProjectionPlane(new PlaneByThreePoints(point1, point2, point3));

TEST(basic, TestOnBasicRender){
    Render* render = new Render();
    render->observer = new GUI();

}
