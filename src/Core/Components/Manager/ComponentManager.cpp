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

void ComponentManager::mapEntityComponentToTable(const EntityID &id, const ComponentID &cId, const ComponentTypeID &typeID)
{
    if (_entityComponentTable.size() <= id) {
        size_t oldSize = _entityComponentTable.size();
        
        _entityComponentTable.resize(oldSize + TABLE_GROWTH);
        memsetTable(oldSize, oldSize + TABLE_GROWTH);
    }
    LOG_F(INFO, "Mapping componentID to table : TYPE ID = %i", typeID);
    _entityComponentTable[id][typeID] = cId;
}

void ComponentManager::unmapEntityComponentFromTable(const EntityID &id, const ComponentID &cID, const ComponentTypeID &typeID)
{
    _entityComponentTable[id][typeID] = INVALID_TYPE_ID;
}

ComponentID ComponentManager::generateComponentID(AComponent *c)
{
    size_t i = 0;

    for (; _componentTable.size(); i++) {
        if (_componentTable[i] == nullptr) {
            _componentTable[i] = c;
            return (ComponentID)i;
        }
    }
    _componentTable.resize(_componentTable.size() + TABLE_GROWTH, nullptr);
    _componentTable[i] = c;
    return (ComponentID)i;
}

void ComponentManager::memsetTable(size_t start, size_t end)
{
    size_t maxComponents = TypeIDCounter<AComponent>::get();

    for (size_t i = start; i < end; i++) {
        _entityComponentTable[i].resize(maxComponents, INVALID_TYPE_ID);
    }
}