#include "canvas.h"
#include "iguiobserver.h"
#include "Renderable.h"
#include "unistd.h"
#include "hintWindow.h"
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
//    for(std::pair<std::string, std::vector<PTR<TwoDEntity>>> step: algorithm){
//        for (int i = 0; i < step.second.size(); i++) {
//            step.second[i]->setRenderable(canvas);
//            step.second[i]->render();
////            sleep(1000);
//        }
//   }
    HintWindow hint;
    int i = 0;
    while (i < algorithm.size()) {
        auto step = algorithm[i];
        if (step.first == "link") {
            this->canvas->addLinkLine(step.second[0], step.second[1]);
            i++;
        } else {
            for (int i = 0; i < step.second.size(); i++) {
                step.second[i]->setRenderable(canvas);
                step.second[i]->render();
            }
            if ((algorithm.size() >= i + 1) && (algorithm[i + 1].first == "link")) {
                printf ("\nmaking connection\n");
                this->canvas->addLinkLine(algorithm[i + 1].second[0], algorithm[i + 1].second[1]);
                i++;
            }
            hint.setText(QString::fromStdString(step.first));
            hint.move(480, 850);
            hint.exec();
            while (hint.movement == 0) {

            }
            i += hint.movement;
        }
    }
}
