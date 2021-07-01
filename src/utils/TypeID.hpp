/*
** Pol Bachelin, 2021
** redCodeEngine
** File description:
** TypeID
*/

#ifndef TYPEID_HPP_
#define TYPEID_HPP_

#include <cstddef>

using TypeID = unsigned int;

template<class T>
class TypeIDCounter {

    static TypeID _count;

    public:

        template<class U>
        static const TypeID get() 
        {
            static const TypeID staticTypeID { _count++ };
            return staticTypeID;
        }

        static const TypeID get() 
        {
            return _count;
        }
};

#endif /* !TYPEID_HPP_ */
