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
#include <vector>
#include <unordered_map>

class ComponentManager {
    public:
        ComponentManager();
        ~ComponentManager();

        template<class T, class... Args>
        T *addComponentToEntity(EntityID id, Args&&... args) {

        }

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

        template<class T>
        void removeComponent(const EntityID &id) {
            
        }


    protected:
        std::unordered_map<ComponentTypeID, IComponentPool *> _componentPools;
        std::vector<AComponent *> _componentTable;
        std::vector<std::vector<ComponentID>> _entityComponentTable;
    private:
};

#endif /* !COMPONENTMANAGER_HPP_ */
