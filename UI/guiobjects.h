#ifndef GUIOBJECTS_H
#define GUIOBJECTS_H

#include <string>

#include "QColor"

using namespace std;

class GUIObjects {
private:
    int id;
protected:
    QColor entityColor;
public:
    virtual int draw ()=0;
    virtual int reDraw ()=0;
    virtual int remove ()=0;
    virtual ~GUIObjects(){}
};

class GUIPoint : protected GUIObjects {
public:
    string pointName;
    int draw ();
    int reDraw ();
    int remove ();
    ~GUIPoint() {}
};

class GUILine : protected GUIObjects {
public:
    string pointNames[2];
    int draw ();
    int reDraw ();
    int remove ();
    ~GUILine () {}

};

class GUIAxis : protected GUIObjects {
    string axisName;
    GUILine baseLine;
public:
    int draw ();
    int reDraw ();
    int remove ();
    ~GUIAxis() {}
};

class GUIPlane : protected GUIObjects {
private:
    GUIAxis planeAxis;
    string planeName;
public:
    GUIPlane() {}
    int draw ();
    int reDraw ();
    int remove ();
    GUIPlane (GUIAxis axis, string name);
    string getPlaneName () {return planeName;}
    ~GUIPlane() {}
};

#endif // GUIOBJECTS_H
