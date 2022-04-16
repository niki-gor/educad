#ifndef GUISTORAGE_H
#define GUISTORAGE_H

#include <vector>

#include "guiobjects.h"

using namespace std;

class GUIStorage {
    vector <GUIPoint> pointsOnScreen;
    vector <GUILine> linesOnScreen;
    vector <GUIPlane> planesOnScreen;
};

#endif // GUISTORAGE_H
