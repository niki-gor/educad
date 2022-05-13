#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "../Entity/Entity.hpp"

class Controller
{
public:
    Controller(ProjectionPlane oxy);
    void onButtonPress();
    void onRMBClick();
    void onLMBClick();
};

#endif // CONTROLLER_H
