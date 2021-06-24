/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** TypeID
*/

#ifndef TYPEID_HPP_
#define TYPEID_HPP_

#include <cstddef>

template<class T>
class TypeID {
    public:
        template<class U>
        static const size_t get() {
            _count++;
            return _count;
        }
        static const size_t get() {
            return _count;
        }
    private:
        static size_t _count;
};

#endif /* !TYPEID_HPP_ */
