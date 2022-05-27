#include "Angem.hpp"
#include <assert.h>
#include "math.h"
#include <iostream>


double AngemUtils::getDistance(AngemPoint p1, AngemPoint p2){
    return pow( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2) , 0.5 );
}

double AngemUtils::getDistance(AngemPoint p, AngemLine l){
    if(isPointOnLine(l, p)){
        return 0;
    }

    const auto& [i, j, k, x1, y1, z1] = l;
    const auto& [x0, y0, z0] = p;

    double it = x1 - x0;
    double jt = y1 - y0;
    double kt = z1 - z0;
    //in jn kn
    //it jt kt
    //i  j  k
    double in = getDeterminant({
                                       {jt, kt},
                                       {j,  k}
                               });
    double jn = -getDeterminant({
                                        {it, kt},
                                        {i,  k}
                                });
    double kn = getDeterminant({
                                       {it, jt},
                                       {i,  j}
                               });
    double distance = sqrt(in*in + jn*jn + kn*kn)/sqrt(i*i+j*j+k*k);
    return distance;
}

double AngemUtils::getDistance(AngemPoint p, AngemPlane pl){
    if(isPointOnPlane(pl, p)) return 0;
    auto const & [A,B,C,D] = pl;
    auto const & [x, y, z] = p;
    double dist = abs(A*x + B*y + C*z + D)/sqrt(A*A + B*B + C*C);
    return dist;
}


double AngemUtils::round(double x, int N){
    static const double powerOfTen[] = { 1.0, 10.0, 100.0, 1000.0, 10000.0 };
    double rounded = floor(x * powerOfTen[N] + 0.5) / powerOfTen[N];
    return rounded;
}

matrix AngemUtils::getAlgAddition(matrix const &  matr, int n, int iDel, int jDel){
    matrix resvec(n-1, std::vector<double>(n-1));
    int i1 = 0;
    int j1 = 0;
    for(int i = 0; i < n; ++i){
        if (i == iDel) continue;
        j1 = 0;
        for(int j = 0; j < n; ++j){
            if(j == jDel) continue;
            resvec[i1][j1++] = matr[i][j];
        }
        i1++;
    }
    return resvec;
}

double AngemUtils::getDeterminant(matrix const &  matr){
    size_t n = matr.size();
    assert(n>=2);
    if(n == 2){
        return matr[0][0]*matr[1][1] - matr[0][1]*matr[1][0];
    } else {
        double result = 0;
        for(int j = 0; j < n; j++){
            result += (1 - j%2*2)*matr[0][j]*getDeterminant( getAlgAddition(matr, n, 0, j));
        }
        return result;
    }
}

AngemPoint AngemUtils::planeLineIntersection(AngemPlane pl, AngemLine l){

    const auto& [i, j, k, x0, y0, z0] = l;
    const auto& [A,B,C,D] = pl;

    //Запишем прямую как пересечение двух плоскостей
    //Первая плоскость
    double A1 = 0;
    double B1 = 0;
    double C1 = 0;
    double D1 = 0;
    //Вторая плоскость
    double A2 = 0;
    double B2 = 0;
    double C2 = 0;
    double D2 = 0;

    if(i){
        //Выражаем все через x
        A1 = j;
        B1 = -i;
        C1 = 0;
        D1 = -x0*j + i*y0;

        A2 = k;
        B2 = 0;
        C2 = -i;
        D2 = -k*x0+i*z0;
    } else if(j){
        //Выражаем все через y
        A1 = j;
        B1 = -i;
        C1 = 0;
        D1 = -x0*j + i*y0;

        A2 = 0;
        B2 = k;
        C2 = -j;
        D2 = -k*y0+j*z0;
    } else{
        //Выражаем все через z
        A1 = k;
        B1 = 0;
        C1 = -i;
        D1 = -k*x0+i*z0;

        A2 = 0;
        B2 = k;
        C2 = -j;
        D2 = -k*y0+j*z0;
    }

    //Найдем точку как пересечение 3 плоскостей
    double det = getDeterminant({ // determinant of main matrix
                                        {A,  B,  C},
                                        {A1, B1, C1},
                                        {A2, B2, C2}
                                });
    assert(det);
    double detX = getDeterminant({ // determinant of X matrix
                                         {D,  B,  C},
                                         {D1, B1, C1},
                                         {D2, B2, C2}
                                 });
    double detY = getDeterminant({ // determinant of Z matrix
                                         {A,  D,  C},
                                         {A1, D1, C1},
                                         {A2, D2, C2}
                                 });
    double detZ = getDeterminant({ // determinant of Z matrix
                                         {A,  B,  D},
                                         {A1, B1, D1},
                                         {A2, B2, D2}
                                 });

    double x = -detX/det;
    double y = -detY/det;
    double z = -detZ/det;

    return AngemPoint(x, y, z);
}

AngemLine AngemUtils::getPerpendicularLine(AngemPoint p, AngemLine l){
    double A = l.i;
    double B = l.j;
    double C = l.k;
    double D = l.i * (-p.x) + l.j*(-p.y) + l.k*(-p.z);
    double x1 = (B*l.x0*l.j + C*l.x0*l.k - B*l.i*l.y0 - C*l.i*l.z0 - D*l.i)/(A*A + B*B + C*C);
    double y1 = (A*l.y0*l.i + C*l.y0*l.k - A*l.j*l.x0 - C*l.j*l.z0 - D*l.j)/(A*A + B*B + C*C);
    double z1 = (A*l.z0*l.i + B*l.z0*l.j - A*l.k*l.x0 - B*l.k*l.y0 - D*l.k)/(A*A + B*B + C*C);
    return AngemLine(p.x - x1, p.y - y1, p.z - z1, p.x, p.y, p.z);
}

AngemLine AngemUtils::getPerpendicularLine(AngemLine l1, AngemLine l2){
    double x1 = 0;
    double y1 = 0;
    double z1 = 0;
    //double x0, y0, z0, i0, j0, k0;
    //auto& [i0, j0, k0, x0, y0, z0] = l1;
    if(l2.i == l1.i && !l2.i){
        y1 = (l1.y0 * l2.j * l1.k + l2.j * l2.z0 * l1.j - l1.j * l2.j * l1.z0 - l1.j * l2.k * l2.y0) / (l2.j * l1.k - l1.j * l2.k);
        z1 = (l1.z0 * l2.k * l1.j + l2.k * l2.y0 * l1.k - l1.k * l2.k * l1.y0 - l1.k * l2.j * l2.z0) / (l2.k * l1.j - l1.k * l2.j);
        x1 = 0;
    } else if (l2.j == l1.j && !l2.j){
        x1 = (l1.x0 * l2.i * l1.k + l2.i * l2.z0 * l1.i - l1.i * l2.i * l1.z0 - l1.i * l2.k * l2.x0) / (l2.i * l1.k - l1.i * l2.k);
        z1 = (l1.z0 * l2.k * l1.i + l2.k * l2.x0 * l1.k - l1.k * l2.k * l1.x0 - l1.k * l2.i * l2.z0) / (l2.k * l1.i - l1.k * l2.i);
        y1 = 0;
    } else if(l2.k == l1.k && !l2.k){
        x1 = (l1.x0 * l2.i * l1.j + l2.i * l2.y0 * l1.i - l1.i * l2.i * l1.y0 - l1.i * l2.j * l2.x0) / (l2.i * l1.j - l1.i * l2.j);
        y1 = (l1.y0 * l2.j * l1.i + l2.j * l2.x0 * l1.j - l1.j * l2.j * l1.x0 - l1.j * l2.i * l2.y0) / (l2.j * l1.i - l1.j * l2.i);
        z1 = 0;
    } else {
        x1 = (l1.x0 * l2.i * l1.j + l2.i * l2.y0 * l1.i - l1.i * l2.i * l1.y0 - l1.i * l2.j * l2.x0) / (l2.i * l1.j - l1.i * l2.j);
        y1 = (l1.y0 * l2.j * l1.i + l2.j * l2.x0 * l1.j - l1.j * l2.j * l1.x0 - l1.j * l2.i * l2.y0) / (l2.j * l1.i - l1.j * l2.i);
        z1 = (l1.z0 * l2.k * l1.j + l2.k * l2.y0 * l1.k - l1.k * l2.k * l1.y0 - l1.k * l2.j * l2.z0) / (l2.k * l1.j - l1.k * l2.j);
    }
    double i = l1.j * l2.k - l1.k * l2.j;
    double j = l1.k * l2.i - l1.i * l2.k;
    double k = l1.i * l2.j - l1.j * l2.i;
    return AngemLine(i, j, k, x1, y1, z1);
}

AngemLine AngemUtils::getPerpendicularLine(AngemPoint p, AngemPlane s){
    return AngemLine(s.A, s.B, s.C, p.x, p.y, p.z);
}

AngemPoint AngemUtils::linesIntersection(AngemLine l1,AngemLine l2){
    double x1 = 0;
    double y1 = 0;
    double z1 = 0;
    if(l2.i == l1.i && !l2.i){
        y1 = (l1.y0 * l2.j * l1.k + l2.j * l2.z0 * l1.j - l1.j * l2.j * l1.z0 - l1.j * l2.k * l2.y0) / (l2.j * l1.k - l1.j * l2.k);
        z1 = (l1.z0 * l2.k * l1.j + l2.k * l2.y0 * l1.k - l1.k * l2.k * l1.y0 - l1.k * l2.j * l2.z0) / (l2.k * l1.j - l1.k * l2.j);
        x1 = 0;
    } else if (l2.j == l1.j && !l2.j){
        x1 = (l1.x0 * l2.i * l1.k + l2.i * l2.z0 * l1.i - l1.i * l2.i * l1.z0 - l1.i * l2.k * l2.x0) / (l2.i * l1.k - l1.i * l2.k);
        z1 = (l1.z0 * l2.k * l1.i + l2.k * l2.x0 * l1.k - l1.k * l2.k * l1.x0 - l1.k * l2.i * l2.z0) / (l2.k * l1.i - l1.k * l2.i);
        y1 = 0;
    } else if(l2.k == l1.k && !l2.k){
        x1 = (l1.x0 * l2.i * l1.j + l2.i * l2.y0 * l1.i - l1.i * l2.i * l1.y0 - l1.i * l2.j * l2.x0) / (l2.i * l1.j - l1.i * l2.j);
        y1 = (l1.y0 * l2.j * l1.i + l2.j * l2.x0 * l1.j - l1.j * l2.j * l1.x0 - l1.j * l2.i * l2.y0) / (l2.j * l1.i - l1.j * l2.i);
        z1 = 0;
    } else {
        x1 = (l1.x0 * l2.i * l1.j + l2.i * l2.y0 * l1.i - l1.i * l2.i * l1.y0 - l1.i * l2.j * l2.x0) / (l2.i * l1.j - l1.i * l2.j);
        y1 = (l1.y0 * l2.j * l1.i + l2.j * l2.x0 * l1.j - l1.j * l2.j * l1.x0 - l1.j * l2.i * l2.y0) / (l2.j * l1.i - l1.j * l2.i);
        z1 = (l1.z0 * l2.k * l1.j + l2.k * l2.y0 * l1.k - l1.k * l2.k * l1.y0 - l1.k * l2.j * l2.z0) / (l2.k * l1.j - l1.k * l2.j);
    }
    return AngemPoint(x1, y1, z1);
}

AngemLine AngemUtils::planesIntersection(AngemPlane pl1,AngemPlane pl2){
    auto const & [A, B, C, D] = pl1;
    auto const & [A1, B1, C1, D1] = pl2;
    //std::cout << A << " " << B << " " << C << " " << D  << std::endl;
    //std::cout << A1 << " " << B1 << " " << C1 << " " << D1 << std::endl;
    //Найдем направляющий вектор
    double i = getDeterminant({
                                      {B,  C },
                                      {B1, C1}
                              });
    double j = -getDeterminant({
                                       {A,  C },
                                       {A1, C1}
                               });
    double k = getDeterminant({
                                      {A,  B },
                                      {A1, B1}
                              });

    double x = 0;
    double y = 0;
    double z = 0;
    if(i){
        //прямая не перпендикулярна X
        x = 0; // B+C+D=0
        double det = getDeterminant({
                                            {B,  C},
                                            {B1, C1}
                                    });
        assert(det);
        double detY = getDeterminant({
                                             {D,  C},
                                             {D1, C1}
                                     });
        double detZ = getDeterminant({
                                             {B,  D},
                                             {B1, D1}
                                     });
        y = -detY/det;
        z = -detZ/det;
    } else if(j){
        //прямая не перпендикулярна Y
        y = 0; // A+C+D=0
        double det = getDeterminant({
                                            {A,  C},
                                            {A1, C1}
                                    });
        assert(det);
        double detX = getDeterminant({
                                             {D,  C},
                                             {D1, C1}
                                     });
        double detZ = getDeterminant({
                                             {A,  D},
                                             {A1, D1}
                                     });
        x = -detX/det;
        z = -detZ/det;
    } else {

        //прямая не перпендикулярна Z
        z = 0; // A+B+D=0
        double det = getDeterminant({
                                            {A,  B},
                                            {A1, B1}
                                    });
        assert(det);
        double detX = getDeterminant({
                                             {D,  B},
                                             {D1, B1}
                                     });
        double detY = getDeterminant({
                                             {A,  D},
                                             {A1, D1}
                                     });
        x = -detX/det;
        y = -detY/det;
    }
    return AngemLine(i,j,k,x,y,z);
}

std::pair<AngemPoint, AngemPoint> AngemUtils::pointOnLine(AngemLine l, AngemPoint p, double distance){
    auto const & [i,j,k,x0,y0,z0] = l;
    auto const & [x1, y1, z1] = p;

    double vecsize = sqrt(i*i + j*j + k*k);
    double xP = x1 + distance * i/vecsize;
    double yP = y1 + distance * j/vecsize;
    double zP = z1 + distance * k/vecsize;

    double xM = x1 - distance * i/vecsize;
    double yM = y1 - distance * j/vecsize;
    double zM = z1 - distance * k/vecsize;

    return std::make_pair(AngemPoint(xP, yP, zP), AngemPoint(xM, yM, zM));
}

AngemLine AngemUtils::parallelLine(AngemLine l, AngemPoint p){
    return AngemLine(l.i, l.j, l.k, p.x, p.y, p.z);
}

AngemPoint AngemUtils::pointOnLine(AngemLine l, double* x, double* y, double* z){
    auto const & [i, j, k, x0, y0, z0] = l;
    if(x == nullptr){
        assert(j != 0 || k != 0 );
        if(j){
            x = new double( (*y*i-y0*i + x0*j)/j);
        } else {
            x = new double( (*z*i-z0*i + x0*k)/k);
        }
    } else if(y == nullptr){
        assert(i != 0 || k != 0 );
        if(i){
            y = new double((*x*j-x0*j + y0*i)/i);
        } else {
            y =new double( (*z*j-z0*j + y0*k)/k);
        }
    } else {
        assert(i != 0 || j != 0 );
        if(i){
            z = new double((*x*k-x0*k + z0*i)/i);
        } else {
            z = new double ((*y*k-y0*k + z0*j)/j);
        }
    }
    return AngemPoint(*x,*y,*z);
}

AngemPoint AngemUtils::pointOnPlane(AngemPlane pl, double* x, double* y, double* z){
    auto const & [A, B, C, D] = pl;
    if(x == nullptr){
        assert(A != 0);
        *x = (-B*(*y) - C*(*z) - D)/A;
    } else if (y == nullptr){
        assert(B != 0);
        *y = (-A*(*x) - C*(*z) - D)/B;
    } else {
        assert(C != 0);
        *z = (-A*(*x) - B*(*y) - D)/C;
    }
    return AngemPoint(*x,*y,*z);
}

bool AngemUtils::isPointOnLine(AngemLine l, AngemPoint p){
    auto const & [i, j, k, x0, y0, z0] = l;
    auto const & [x, y, z] = p;
    if(i == 0 && x!=x0) return false;
    if(j == 0 && y!=y0) return false;
    if(k == 0 && z!=z0) return false;
    if(i == 0 && j == 0) return true;
    if(i == 0 && k == 0) return true;
    if(j == 0 && k == 0) return true;
    if(i){
        if(j){
            if(x-x0/i != y-y0/j) return false;
        }
        if(k){
            if(x-x0/i != z-z0/k) return false;
        }
    } else if(j){
        if(i){
            if(y-y0/j != x-x0/i) return false;
        }
        if(k){
            if(y-y0/j != z-z0/k) return false;
        }
    } else {
        if(i){
            if(z-z0/k != x-x0/i) return false;
        }
        if(j){
            if(z-z0/k != y-y0/j) return false;
        }
    }
}

bool AngemUtils::isPointOnPlane(AngemPlane pl, AngemPoint p){
    auto const & [A, B, C, D] = pl;
    auto const & [x, y, z] = p;
    return A*x + B*y + C*z + D == 0;
}

AngemPoint AngemUtils::getProjectionOnPlane(AngemPlane pl, AngemPoint p){
    if( isPointOnPlane(pl, p) ){
        return p;
    }
    AngemLine perpendicular = getPerpendicularLine(p, pl);
    return planeLineIntersection(pl, perpendicular);
}
AngemPoint AngemUtils::getProjectionOnLine(AngemLine l, AngemPoint p){
    if( isPointOnLine(l, p) ){
        return p;
    }
    AngemLine perpendicular = getPerpendicularLine(p, l);
    return linesIntersection(l, perpendicular);
}