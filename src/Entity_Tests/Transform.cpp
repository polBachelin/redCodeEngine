/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** Transform
*/

#include "Transform.hpp"

Transform::Transform(int x, int y) : _x(x), _y(y)
{
    LOG_F(INFO, "Creating Transform Component");
}

Transform::~Transform()
{
    LOG_F(INFO, "Destroying Transform Component");
}

const std::tuple<int, int> Transform::getPos() const
{
    return std::make_tuple(_x, _y);
}

void Transform::setPos(std::tuple<int, int> pos)
{
    _x = std::get<0>(pos);
    _y = std::get<1>(pos);
}