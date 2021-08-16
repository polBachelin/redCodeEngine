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
        ComponentPool<T> *getComponentPool() {
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
        T *addComponentToEntity(EntityID id, Args&&... args) {
            AComponent *c = getComponentPool<T>()->createComponent();
            ComponentID cID = generateComponentID(c);

            c->_owner = id;
            LOG_F(INFO, "Created component with ID : %i || and || TYPE : %s", cID, getComponentPool<T>()->getTypeName());
            return static_cast<T *>(c);
        }

        template<class T>
        void removeComponent(const EntityID &id) {
            ComponentTypeID componentTypeID = T::_componentTypeID;
            ComponentID componentID = _entityComponentTable[id][componentTypeID];
            AComponent *component = _componentTable[componentID];
            ComponentPool<T> *pool = getComponentPool<T>();

            if (component == nullptr) {
                LOG_F(ERROR, "Could not find component with type %s on Entity with ID %i", pool->getTypeName(), id);
                return;
            }
            pool->destroyComponent(component);
            unmapEntityComponentFromTable(id, componentID, componentTypeID);
        }

        void removeAllComponents(const EntityID &id) {
        }

        template<class T>
        T *retrieveComponent(const EntityID &id) {

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
