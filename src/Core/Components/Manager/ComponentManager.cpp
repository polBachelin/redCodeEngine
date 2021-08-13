/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

ComponentManager::ComponentManager()
{
    LOG_F(INFO, "Initializing Component Manager");
    _entityComponentTable.resize(TABLE_GROWTH);
    memsetTable(0, TABLE_GROWTH);
}

ComponentManager::~ComponentManager()
{
    LOG_F(INFO, "Destroying Component Manager");
    for (auto it : _componentPools) {
        delete it.second;
    }
}

void ComponentManager::mapEntityComponentToTable(const EntityID &id, const ComponentID &cId)
{
    if (_entityComponentTable.size() <= id) {
        size_t oldSize = _entityComponentTable.size();
        
        _entityComponentTable.resize(oldSize + TABLE_GROWTH);
        memsetTable(oldSize, oldSize + TABLE_GROWTH);
    }
    _entityComponentTable[id].push_back(cId);
}

void ComponentManager::unmapEntityComponentFromTable(const EntityID &id)
{

}

void ComponentManager::memsetTable(size_t start, size_t end)
{
    size_t maxComponents = TypeIDCounter<AComponent>::get();

    for (size_t i = start; i < end; i++) {
        _entityComponentTable[i].resize(maxComponents, INVALID_TYPE_ID);
    }
}