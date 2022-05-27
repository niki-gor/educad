#ifndef ANGEM_HPP
#define ANGEM_HPP

#include <memory>
#include "utils.h"
#include "AngemEntity.h"
#include <vector>


using matrix = std::vector<std::vector<double>>;


namespace AngemUtils {
    double getDistance(AngemPoint p1, AngemPoint p2); // Расстояние от точки до точки
    double getDistance(AngemPoint p, AngemLine l); // Расстояние от точки до прямой
    double getDistance(AngemPoint p, AngemPlane pl); // Расстояние от точки до плоскости
    AngemLine getPerpendicularLine(AngemPoint p, AngemLine l); // Перпендикуляр от точки до прямой
    double getDeterminant(matrix const &  matr); // Определитель матрицы любого порядка.
    matrix getAlgAddition(matrix const &  matr, int n, int iDel, int jDel); // Алгебраическое дополнение элемента матрицы
    AngemLine getPerpendicularLine(AngemLine l1, AngemLine l2); // Перпендикуляр от пересекающихся прямых
    AngemPoint planeLineIntersection(AngemPlane p, AngemLine l); // Точка пересечения плоскости и прямой
    AngemLine getPerpendicularLine(AngemPoint p, AngemPlane s); // Перпендикуляр от точки до плоскости
    AngemPoint linesIntersection(AngemLine l1,AngemLine l2); // Точка пересечения двух прямых
    AngemLine planesIntersection(AngemPlane pl1,AngemPlane pl2); // Линия пересечения двух плоскостей
    AngemLine parallelLine(AngemLine l, AngemPoint p); // Прямая, параллельная исходной прямой и проходящая через исходную точку.
    double round(double x, int N=2); // Округление (по дефолту до 0.01)
    AngemPoint pointOnLine(AngemLine l, double* x, double* y, double* z); // Получить точку на прямой по двум координатам. 3 координату указать как nullptr.
    std::pair<AngemPoint, AngemPoint> pointOnLine(AngemLine l, AngemPoint p, double distance); // Точка на прямой, находящаяся на заданном расстоянии от исходной точки.
    AngemPoint pointOnPlane(AngemPlane pl, double* x, double* y, double* z); // Получить точку на плоскости по двум координатам. 3 координату указать как nullptr.
    bool isPointOnLine(AngemLine l, AngemPoint p); // Лежит ли точка на линии
    bool isPointOnPlane(AngemPlane pl, AngemPoint p); // Лежит ли точка на плоскости
    AngemPoint getProjectionOnPlane(AngemPlane pl, AngemPoint p); // Проекция точки на плоскость
    AngemPoint getProjectionOnLine(AngemLine l, AngemPoint p); // Проекция точки на прямую.
};

#endif