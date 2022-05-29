#include "canvas.h"
#include "iguiobserver.h"
#include "Renderable.h"
#include "unistd.h"
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

void GUIAPI::onAddAlgorithm(std::vector<std::pair<std::string, std::vector<PTR<TwoDEntity>>>> algorithm) {
    for(std::pair<std::string, std::vector<PTR<TwoDEntity>>> step: algorithm){
        for (int i = 0; i < step.second.size(); i++) {
            step.second[i]->setRenderable(canvas);
            step.second[i]->render();
//            sleep(1000);
        }
    }
}
