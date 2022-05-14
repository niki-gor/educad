#include "AngemModelWorker.hpp"

PTR<Entity> AngemModelWorker::AddToModel(PTR<Entity> p){
    render->addEntity(p);
    container->insert(p);
}

void AngemModelWorker::DeleteEntity(PTR<Entity> p){
    render->deleteEntity(p);
    container->erase(p);
}

void AngemModelWorker::DeleteRecurs(PTR<Entity> p){
    std::vector<PTR<Entity>> children = p->getChildren();
    for(const auto&i : children ){
        this->DeleteRecurs(i);
    }
    render->deleteEntity(p);
    container->erase(p);
}