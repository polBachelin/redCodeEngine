/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** EntityPool
*/

#ifndef ENTITYPOOL_HPP_
#define ENTITYPOOL_HPP_

#include "IEntityPool.hpp"

template<class T>
class EntityPool : public IEntityPool {
    public:
        EntityPool();
        virtual ~EntityPool();

        void destroyEntity(AEntity *e) {
            e->~AEntity();
        }
    protected:
    private:
};

#endif /* !ENTITYPOOL_HPP_ */
