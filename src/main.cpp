/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** main
*/

#include "Table.hpp"
#include "Bomb.hpp"

int main(void)
{
    Table<AEntity, EntityID> tab;
    Bomb *test = new Bomb();

    tab.addObjectToTable(test);

    return 0;
}