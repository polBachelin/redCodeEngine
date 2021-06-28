// RedCode Engine
// Pol Bachelin
// Courtesy of : https://www.gamedev.net/articles/programming/general-and-gameplay-programming/c-custom-memory-allocation-r3010/

#include <functional>
#include <cstdint>

class Allocator {
    public:
        Allocator(size_t size, void *start);
        virtual ~Allocator();

        virtual void allocate(size_t s, uint8_t alignment = 8) = 0;
        virtual void free(void *p) = 0;

        size_t getSize() const noexcept;
        size_t getMemoryUsed() const noexcept;
        size_t getNbAllocs() const noexcept;
        void *getStart() const noexcept;
    private:
        size_t _size;
        size_t _memoryUsed;
        size_t _nbAllocs;
        void *_start;
};

namespace allocator
{
    template <class T> T* allocateNew(Allocator& allocator)
    {
        return new (allocator.allocate(sizeof(T), __alignof(T))) T;
    }

    template <class T> T* allocateNew(Allocator& allocator, const T& t)
    {
        return new (allocator.allocate(sizeof(T), __alignof(T))) T(t);
    }

    template <class T> void deallocateDelete(Allocator& allocator, T& object)
    {
        object.~T();
        allocator.free(&object);
    }

    template <class T> T* allocateArray(Allocator& allocator, size_t length)
    {
        uint8_t headerSize = sizeof(size_t)/sizeof(T);

        if(sizeof(size_t)%sizeof(T) > 0) headerSize += 1;

        //Allocate extra space to store array length in the bytes before the array
        T* p = ( (T*) allocator.allocate(sizeof(T)*(length + headerSize), __alignof(T)) ) + headerSize;
        
        *( ((size_t*)p) - 1 ) = length;
        for (size_t i = 0; i < length; i++)
            new (&p) T;
        return p;
    }

    template <class T> void deallocateArray(Allocator& allocator, T* array)
    {
        size_t length = *( ((size_t*)array) - 1 );

        for (size_t i = 0; i < length; i++) array.~T();
        
        //Calculate how much extra memory was allocated to store the length before the array
        uint8_t headerSize = sizeof(size_t)/sizeof(T);
        if(sizeof(size_t)%sizeof(T) > 0)
            headerSize += 1;
        allocator.free(array - headerSize);
    }
};
