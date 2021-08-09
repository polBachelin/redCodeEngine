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
}