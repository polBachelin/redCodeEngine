/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** EntityPool
*/

#ifndef ENTITYPOOL_HPP_
#define ENTITYPOOL_HPP_

#include "IEntityPool.hpp"
#include <list>

template<class T>
class EntityPool : public IEntityPool {
    public:
        EntityPool() {
            std::cout << "Creating entity Pool" << std::endl;
        };
        virtual ~EntityPool() {};

        AEntity *createObject() {
            AEntity *e = new T();

            _objects.push_back(e);
            return e;
        }
        void destroyEntity(AEntity *e) {
            e->~AEntity();
        }
    protected:
        std::list<AEntity *> _objects;
    private:
};

#endif /* !ENTITYPOOL_HPP_ */
