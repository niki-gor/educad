#include "canvas.h"
#include "iguiobserver.h"
#include "Renderable.h"
//#include "TwoDEntity/TwoDEntity.h"

void GUIAPI::onAddToProjectionPlane(std::shared_ptr<TwoDEntity> object) {
    object->setRenderable(canvas);
    object->render();
}

void GUIAPI::onChangeFromProjectionPlane(std::shared_ptr<TwoDEntity> object) {
    object->setRenderable(canvas);
    object->render();
}

void GUIAPI::onDeleteFromProjectionPlane(std::shared_ptr<TwoDEntity> object) {
    object->setRenderable(canvas);
    object->render();
}
