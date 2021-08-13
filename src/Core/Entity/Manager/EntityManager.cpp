/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

EntityManager::EntityManager()
{
    LOG_F(INFO, "Initializing EntityManager!");
}

EntityManager::~EntityManager()
{
    LOG_F(INFO, "Cleaning EntityManager!");
    for (auto it : _entityPools) {
        delete it.second;
        it.second = nullptr;
    }
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
        DLOG_F(INFO, "Destroying entity of type : %s", it->second->getEntityTypeName());
        if (it == _entityPools.end()) {
            DLOG_F(WARNING, "No more entities in the Pool, stopping");
            return;
        }
        //TODO remove components from entity
        it->second->destroyEntity(e);
        destroyEntityID(id);
    }
    _toDestroyEntities.clear();
}