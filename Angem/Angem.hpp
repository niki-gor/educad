#pragma once



class AngemEntity {
};

class AngemPoint {
public:
    double x;
    double y;
    double z;
};

class AngemLine {
public:
    // i j k -- направляющий вектор
    double i;
    double j;
    double k;
    double x0;
    double y0;
    double z0;
};

class AngemPlane {
public:
    double A;
    double B;
    double C;
    double D;
};

class AngemUtils {
public:
    float getDistance(AngemPoint p1, AngemPoint p2){
        return 0;
    }
    AngemLine getPerpendicularLine(AngemPoint p, AngemLine l){
        return AngemLine();
    }
};

