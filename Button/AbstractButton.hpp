#pragma once

#include "SFML/Graphics.hpp"
#include <memory>
#include "Utils.hpp"



class Vector2D {
public:
    virtual float x() const = 0;
    virtual float y() const = 0;
    virtual void setX(float x) = 0;
    virtual void setY(float y) = 0;
    virtual ~Vector2D();
};

class Button {
public:
    virtual void draw() const = 0;
    virtual void hover() const = 0;
    virtual ~Button();
};

class SFMLVector2D : public Vector2D {
protected:
    float x;
    float y;
public:
    float x() const override;
    float y() const override;
    void setX(float x) override;
    void setY(float y) override;
};

class GUIFactory {
public:
    virtual PTR<Button> createButton() const = 0;
    ~GUIFactory();
};

class SFMLGUIFactory : public GUIFactory {
public:
    PTR<Button> createButton() const override;
};

class SFMLButton : public Button, public SFMLVector2D {
    void draw() const override;
};