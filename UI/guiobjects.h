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
    string pointName;
    int draw ();
    int reDraw ();
    int remove ();
public:
    ~GUIPoint() {}
};

class GUILine : protected GUIObjects {
    string pointNames[2];
    int draw ();
    int reDraw ();
    int remove ();
public:
    ~GUILine () {}

};

class GUIAxis : protected GUIObjects {
    string axisName;
    GUILine baseLine;
    int draw ();
    int reDraw ();
    int remove ();
public:
    ~GUIAxis() {}
};

class GUIPlane : protected GUIObjects {
    GUIAxis planeAxis;
    string planeName;
    int draw ();
    int reDraw ();
    int remove ();
public:
    GUIPlane (GUIAxis axis, string name);
    string getPlaneName () {return planeName;}
    ~GUIPlane() {}
};

#endif // GUIOBJECTS_H
