/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include "Entity.hpp"
#include "EntityPool.hpp"
#include "EntityTable.hpp"
#include "ComponentManager.hpp"
#include <unordered_map>
#include <vector>
#include "loguru.hpp"

class EntityManager {
    public:
        EntityManager(ComponentManager *componentManager);
        ~EntityManager();

        template<class T, class... Args>
        EntityID createEntity(Args&&... args) {
            AEntity *e = new T(std::forward<Args>(args)...);
            EntityID eID = generateEntityID(e);

            getEntityPool<T>()->addObject(e);
            e->setEntityID(eID);
            LOG_F(INFO, "Created entity with ID : %i || and || TYPE : %s", eID, getEntityPool<T>()->getEntityTypeName());
            return eID;
        }

        template<class T>
        EntityPool<T> *getEntityPool() {
            EntityTypeID id = T::_entityTypeID;
            EntityPool<T> *pool = nullptr;

            auto i = _entityPools.find(id);
            if (i == _entityPools.end()) {
                pool = new EntityPool<T>();
                _entityPools[id] = pool;
            } else {
                pool = (EntityPool<T> *)i->second;
            }
            return pool;
        }

        void destroyEntity(const EntityID &id) {
            _toDestroyEntities.push_back(id);
            _numberEntitiesToDestroy++;
        }

        EntityID generateEntityID(AEntity *e);
        ComponentManager *getComponentManager() const;
        void destroyEntityID(EntityID id);
        void cleanDestroyedEntities();

    private:
        std::unordered_map<EntityTypeID, IEntityPool *> _entityPools;
        EntityTable _entityTable;
        std::vector<EntityID> _toDestroyEntities;
        size_t _numberEntitiesToDestroy;
        ComponentManager *_componentManager;
};

#endif /* !ENTITYMANAGER_HPP_ */
