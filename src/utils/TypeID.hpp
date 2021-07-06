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

    static inline TypeID _count;

    public:

        template<class U>
        static TypeID get() 
        {
            static TypeID staticTypeID { _count++ };
            return staticTypeID;
        }

        static TypeID get() 
        {
            return _count;
        }
};

#endif /* !TYPEID_HPP_ */
