#include "line2d.h"



 bool Line2DbyTwoPoints::isInitial() const {
     return false;
 }

 void Line2DbyTwoPoints::update() {
     Entity2D::update();
 }

 Line2DbyTwoPoints::Line2DbyTwoPoints(PTR<Entity2D> first, PTR<Entity2D> second) : first{first}, second{second} {

 }



 bool Line2DbyPointAndParallel::isInitial() const {
     return false;
 }

 void Line2DbyPointAndParallel::update() {

 }