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
#include "Table.hpp"
#include <unordered_map>
#include <vector>

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();

        template<class T, class... Args>
        EntityID createEntity(Args&&... args) {
            AEntity *e = getEntityPool<T>()->createObject();
            EntityID eID = generateEntityID(e);

            e->setEntityID(eID);
            std::cout << "Created entity with ID == " << eID << std::endl;
//            AEntity *entity = new (e)T(std::forward<Args>(args)...);
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

        EntityID generateEntityID(AEntity *e);
        void destroyEntityID(EntityID id);
        void cleanDestroyedEntities();

    private:
        std::unordered_map<EntityTypeID, IEntityPool *> _entityPools;
        Table _entityTable;
        std::vector<EntityID> _toDestroyEntities;
        size_t _numberEntitiesToDestroy;
};

#endif /* !ENTITYMANAGER_HPP_ */
