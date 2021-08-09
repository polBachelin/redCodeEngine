/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** TypeID
*/

#ifndef TYPEID_HPP_
#define TYPEID_HPP_

#include <cstddef>
#include <iostream>
using TypeID = unsigned int;

template<class T>
class TypeIDCounter {

    static inline TypeID _count;

    public:

        template<class U>
        static TypeID get() 
        {
            static TypeID staticTypeID { _count++ };
            std::cout << "Type count " << _count << std::endl;
            return staticTypeID;
        }

        static TypeID get() 
        {
            std::cout << "Type count " << _count << std::endl;
            return _count;
        }
};

#endif /* !TYPEID_HPP_ */
