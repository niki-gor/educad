#include "Algo.hpp"



PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane, PTR<Point> point) {
    // если на нашей плоскости проекций уже есть проекция точки, то просто возвращаем ее
    if (auto result = projectionPlane->getProjection(point); result != nullptr) {
        return result;
    }
    // перебираем смежные проекции с помощью поиска в глубину (лучше в ширину, но в примере пофиг)
    for (auto& adjacentProjectionPlane : projectionPlane->getAdjacent()) {
        if (auto adjacentProjection = getProjection(adjacentProjectionPlane, point); adj != nullptr) {
            // строим линию связи из смежной проекции к текущей
            auto linkLine = getlinkLine(adjacentProjection, projectionPlane); ???
            // добавляем в матмодель проекцию точки на текущую плоскость проекций
            mathModel.addProjection(point, projectionPlane); ???
            return projectionPlane->getProjection(point);
        }
    }
    return nullptr;
}

PTR<TwoDEntity> getIntersection(PTR<ProjectionPlane> projectionPlane, PTR<Line> first, PTR<Line> second) {
    auto point = get(PointByLinesIntersection(first, second));
    return getProjection(projectionPlane, point);
}

PTR<TwoDEntity> getParallelLine(PTR<ProjectionPlane> projectionPlane, PTR<Point> point, PTR<Line> parallel) {
    auto line = get(LineByParallel(point, parallel));
    return getProjection(projectionPlane, line);
}

PTR<TwoDEntity> getPerpendicular(PTR<ProjectionPlane> projectionPlane, PTR<Point> point, PTR<Line> perpendicular) {
    auto line = get(LineByPerpendicular(point, perpendicular));
    auto intersection = get(PointByLinesIntersection(line, perpendicular));
    return getProjection(projectionPlane, intersection);
}

PTR<TwoDEntity> getPointOnPlane(PTR<ProjectionPlane> projectionPlane, PTR<Point> point, PTR<Plane> plane) {
    //std::vector<PTR<Entity>> parents = plane->getParents();
    Polyset<Entity> parents;
    // если по трем точкам
    if (parents[typeid(Point)].size() == 3) {
        auto begin = parents[typeid(Point)].begin();
        auto first = *begin;
        auto second = *std::next(begin);
        auto third = *std::next(std::next(begin));
        storage->AddToModel(new LineByTwoPoints(first, second));
        storage->AddToModel(new LineByTwoPoints(first, third));
        
        storage->get(new LineByTwoPoints(first, second));
        storage->get(new LineByTwoPoints(first, second));
        
        auto line = storage->get(new LineByParallel(std::dynamic_pointer_cast<Point>(second), std::dynamic_pointer_cast<Point>(third)));
        auto parallel = storage->get(new LineByParallel(point, line));
        auto parallel = storage->get(new LineByParallel(second, third));

        auto stogage->get(new LineByParallel()
    }
}