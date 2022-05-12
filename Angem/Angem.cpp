#include "Angem.hpp"

double AngemUtils::getDistance(AngemPoint p1, AngemPoint p2){
    return pow( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2) , 0.5 );
}