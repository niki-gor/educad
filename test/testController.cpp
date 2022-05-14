//
// Created by Марат Гасанов on 14.05.2022.
//

#include "gtest/gtest.h"
#include "iostream"
#include "controller.h"
#include "ControllerObservable.h"

class UI{
    ControllerObservable* controller;
public:
    void clickMouse(){
        controller->onAddEntity((PTR<Point>(new PointByCoords(1,1,1))));
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
};

TEST(basic, Test){
    ControllerObservable* controller = new Controller();
    UI ui = UI(controller);
    ui.clickMouse();
    ui.doubleClickMouse();
    EXPECT_NO_THROW();
}