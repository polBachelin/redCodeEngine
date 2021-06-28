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
#include <unordered_map>
#include <vector>

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();


        template<class T, class... Args>
        static const EntityID createEntity(Args... args);
        //static const Entity *getEntity(const EntityID &id);
        static void destroyEntity(const EntityID &id);

        template<class T>
        EntityPool<T> *getEntityPool() {
            EntityTypeID id = T::STATIC_ENTITY_TYPE_ID;
            EntityPool<T> *pool = nullptr;

            auto i = _entityPools.find(id);
            if (i == _entityPools.end()) {
                pool = new EntityPool<T>();
                _entityPools[id] = pool;
            } else {
                pool = i->second;
            }
            return pool;
        }
    private:
        std::unordered_map<EntityTypeID, IEntityPool *> _entityPools;
        std::vector<EntityID> _toDestroyEntities;
};

#endif /* !ENTITYMANAGER_HPP_ */
