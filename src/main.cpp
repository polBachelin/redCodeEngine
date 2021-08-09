/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** main
*/

#include "Table.hpp"
#include "Bomb.hpp"
#include "EntityManager.hpp"
#include "EntityPool.hpp"
#include <iostream>

int main(void)
{
    std::cout << "---- STARTING MAIN ----" << std::endl;
    EntityManager manager;

    manager.createEntity<Bomb>();
    manager.createEntity<Bomb>();
    manager.destroyEntityID(0);
    //Bomb *test = new Bomb();
    //Bomb *nb = new Bomb();

    // std::cout << tab.addObjectToTable(test) << std::endl;
    // std::cout << tab.addObjectToTable(nb) << std::endl;
    // std::cout << nb->getEntityID() << std::endl;
    // std::cout << test->getEntityTypeID() << std::endl;
    
    return 0;
}