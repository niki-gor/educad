#include "AngemModelWorker.hpp"

PTR<Entity> AngemModelWorker::AddToModel(PTR<Entity> p){
    //render->addEntity(p);
    container->insert(p);
}

void AngemModelWorker::DeleteEntity(PTR<Entity> p){
    //render->deleteEntity(p);
    container->erase(p);
}

void AngemModelWorker::DeleteRecurs(PTR<Entity> p){
    std::vector<PTR<Entity>> parents = p->getParents();
    for(const auto&  i : parents ){
        this->DeleteRecurs(i);
    }
    //render->deleteEntity(p);
    container->erase(p);
}