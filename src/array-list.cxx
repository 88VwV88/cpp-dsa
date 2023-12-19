#include <stdexcept>
#include <cstring>

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
        constexpr List(std::initializer_list<T> args): bits(1), _size(0) {
            for (auto it: args)
                push(it);
        }
        ~List()
        {
            delete ptr;
        }
        constexpr void append(T elem)
        {   if (_size == 0)
            {
                ptr = new T[bits]{};
                ptr[0] = elem;
            }
            else
            {
                if (bits == _size)
                    bits *= 2;

                T* temp = new T[bits]{};
                std::copy(ptr, ptr+_size, temp+1);
                delete ptr;

                temp[0] = elem;
                ptr = temp;
            }
            _size++;
        }
        constexpr void add(T elem, size_t index)
        {
            if (index > _size)
                throw std::length_error("AddIndexOutOfBounds");
            if (index == 0)
                append(elem);
            else if (index == _size)
                push(elem);
            else
            {
                if (bits == _size)
                    bits *= 2;
                T* temp = new T[bits]{};

                std::copy(ptr, ptr+index, temp);
                temp[index] = elem;

                std::copy(ptr+index, ptr+_size, temp+index+1);
                delete ptr;

                ptr = temp;
                _size++;
            }
        }
        constexpr void push(T elem)
        {
            if (_size == 0)
                ptr = new T[bits];
            else
            {
                if (bits == _size)

                    bits *= 2;
                T *temp = new T[bits]{};
                std::copy(ptr, ptr+_size, temp);
                delete ptr;

                ptr = temp;
            }
            ptr[_size++] = elem;
        }
        constexpr T get(size_t index)
        {
            if (index >= _size)
                throw std::length_error("GetIndexOutOfBounds");
            return ptr[index];
        }
        constexpr T pop()
        {
            if (_size == 0)
                throw std::length_error("PoppingEmptyList");
            _size--;
            return ptr[_size];
        }
        constexpr T popLeft() 
        {
            if (_size == 0)
                throw std::length_error("PoppingEmptyList");
            T old{ ptr[0] };
            _size--;
            while ((bits / 2) > _size)
                bits /= 2;
            T* temp = new T[bits];
            return old;
        }
        constexpr T* begin() { return ptr; }
        constexpr T* end() { return ptr + _size; }
    };
};