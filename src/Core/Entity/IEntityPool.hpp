/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** IEntityPool
*/

#ifndef IENTITYPOOL_HPP_
#define IENTITYPOOL_HPP_

#include "AEntity.hpp"

class IEntityPool {
    public:
        virtual ~IEntityPool() {};
        
        virtual void destroyEntity(AEntity *) = 0;
};

#endif /* !IENTITYPOOL_HPP_ */
