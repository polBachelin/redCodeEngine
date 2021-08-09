/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

EntityManager::EntityManager()
{
    std::cout << "Initializing EntityManager!" << std::endl;
}

EntityManager::~EntityManager()
{
    cleanDestroyedEntities();
    std::cout << "Destroying EntityManager!" << std::endl;
}

EntityID EntityManager::generateEntityID(AEntity *e)
{
    return _entityTable.addObjectToTable(e);
}

void EntityManager::destroyEntityID(EntityID id)
{
    _entityTable.removeObjectFromData(id);
}

void EntityManager::cleanDestroyedEntities()
{
    for (auto i : _toDestroyEntities) {
        EntityID id = i;
        AEntity *e = _entityTable[id];
        EntityTypeID typeID = e->getEntityTypeID();

        auto it = _entityPools.find(typeID);
        if (it == _entityPools.end()) {
            std::cout << "could not find pool\n";
            return;
        }
        //TODO remove components from entity
        it->second->destroyEntity(e);
        destroyEntityID(id);
    }
    _toDestroyEntities.clear();
}