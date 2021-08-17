/*
** EPITECH PROJECT, 2021
** redCodeEngine
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "Component.hpp"
#include <tuple>

class Transform : public Component<Transform> {
    public:
        Transform(int x, int y);
        ~Transform();

        const std::tuple<int, int> getPos() const;
        void setPos(std::tuple<int, int> pos);
    protected:
        int _x;
        int _y;
    private:
};

#endif /* !TRANSFORM_HPP_ */
