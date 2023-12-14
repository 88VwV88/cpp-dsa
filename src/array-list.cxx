#include <stdexcept>
#include <iostream>

namespace list 
{   
    template<typename T> 
    class List
    {
        T* ptr;
        size_t bits, _size;
    public:
        constexpr const size_t size() { return this->_size; }
        constexpr List(): ptr(nullptr), bits(1), _size(0) {}
        ~List()
        {
            delete ptr;
        }
        constexpr void push(T elem)
        {
            if (_size == 0)
                ptr = new T[bits];
            else if (_size == bits)
            {
                bits *= 2;
                T *temp = new T[bits];
                memcpy(temp, ptr, _size * sizeof(T));
                delete ptr;
                ptr = temp;
            }
            ptr[_size++] = elem;
        }
        constexpr T get(size_t index)
        {
            if (index >= _size)
                throw std::length_error("IndexOutOfBounds");
            return ptr[index];
        }
        constexpr T pop()
        {
            if (_size == 0)
                throw std::length_error("PoppingEmptyList");
            _size--;
            return ptr[_size];
        }
    };
};