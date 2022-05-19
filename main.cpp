#include "iostream"
#include "ControllerObservable.h"
#include "controller.h"

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

int main(){
    PTR<GUIObserver> observer(new GUI());
    Render render = Render(observer);
    ControllerObservable* controller = new Controller(render);
//    UI ui = UI(controller);
//    ui.clickMouse();
//    ui.doubleClickMouse();
}