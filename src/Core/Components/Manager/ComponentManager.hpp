/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include "ComponentPool.hpp"
#include "Component.hpp"
#include "GlobalVariables.hpp"
#include "loguru.hpp"
#include <vector>
#include <unordered_map>

class ComponentManager {
    public:
        ComponentManager();
        ~ComponentManager();

        template<class T>
        ComponentPool<T> *getComponentPool() 
        {
            ComponentTypeID id = T::_componentTypeID;
            ComponentPool<T> *pool = nullptr;

            auto i = _componentPools.find(id);
            if (i == _componentPools.end()) {
                pool = new ComponentPool<T>();
                _componentPools[id] = pool;
            } else {
                pool = (ComponentPool<T> *)i->second;
            }
            return pool;
        }

        template<class T, class... Args>
        T *addComponentToEntity(EntityID id, Args&&... args) 
        {
            AComponent *c = new T(std::forward<Args>(args)...);
            ComponentID cID = generateComponentID(c);
            
            getComponentPool<T>()->addComponent(c);
            c->setOwner(id);
            mapEntityComponentToTable(id, cID, T::_componentTypeID);
            LOG_F(INFO, "Created component with ID : %i || and || TYPE : %s", cID, getComponentPool<T>()->getTypeName());
            return static_cast<T *>(c);
        }

        template<class T>
        AComponent *retrieveAComponent(const EntityID &id)
        {
            ComponentTypeID componentTypeID = T::_componentTypeID;
            ComponentID componentID = _entityComponentTable[id][componentTypeID];
            return _componentTable[componentID];
        }

        template<class T>
        void removeComponent(const EntityID &id) 
        {
            ComponentPool<T> *pool = getComponentPool<T>();
            ComponentTypeID componentTypeID = T::_componentTypeID;
            ComponentID componentID = _entityComponentTable[id][componentTypeID];
            AComponent *component = _componentTable[componentID];

            if (component == nullptr) {
                LOG_F(ERROR, "Could not find component with type %s on Entity with ID %i", pool->getTypeName(), id);
                return;
            }
            pool->destroyComponent(component);
            unmapEntityComponentFromTable(id, T::_componentTypeID, componentTypeID);
        }

        void removeAllComponents(const EntityID &id) 
        {
            size_t nbComponents = _entityComponentTable[id].size();

            LOG_F(WARNING, "Nb components %li", nbComponents);
            for (size_t i = 0; i < nbComponents; i++) {
                ComponentID componentId = _entityComponentTable[id][i];
                if (componentId == (ComponentID)INVALID_TYPE_ID)
                    continue;
                AComponent *c = _componentTable[componentId];
                if (c == nullptr)
                    continue;
                auto pool = _componentPools.find(i);
                if (pool != _componentPools.end()) {
                    LOG_F(WARNING, "Calling destroy component from pool");
                    pool->second->destroyComponent(c);
                } else
                    LOG_F(ERROR, "Trying to destroy non-existant component");
                unmapEntityComponentFromTable(id, componentId, i);
            }
        }

        template<class T>
        T *retrieveComponent(const EntityID &id) 
        {
            AComponent *c = retrieveAComponent<T>(id);

            if (c == nullptr) {
                LOG_F(ERROR, "Could not find component with type %s on Entity with ID %i", getComponentPool<T>()->getTypeName(), id);
                return nullptr;
            }
            return static_cast<T *>(c);
        }

        ComponentID generateComponentID(AComponent *c);
        void mapEntityComponentToTable(const EntityID &id, const ComponentID &cId, const ComponentTypeID &typeID);
        void unmapEntityComponentFromTable(const EntityID &id, const ComponentID &cID, const ComponentTypeID &typeID);
        void memsetTable(size_t start, size_t end);

    protected:
        std::unordered_map<ComponentTypeID, IComponentPool *> _componentPools;
        std::vector<AComponent *> _componentTable;
        std::vector<std::vector<ComponentID>> _entityComponentTable;
    private:
};

#endif /* !COMPONENTMANAGER_HPP_ */
