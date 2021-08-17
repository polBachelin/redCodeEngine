/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Entity.hpp"
#include "loguru.hpp"
#include "Transform.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"

class Bomb : public Entity<Bomb>{
    public:
        Bomb();
        ~Bomb();
        friend class ComponentManager;
    protected:
        Transform *_pos;
    private:
};

#endif /* !BOMB_HPP_ */
