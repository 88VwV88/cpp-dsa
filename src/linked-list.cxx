#ifndef __LINKED_LIST_CXX__
#   define __LINKED_LIST_CXX__
#   include <iostream>

namespace llst {
    template<typename T>
    class List 
    {
        class Node 
        {
        public:
            T data;
            Node* next;
            constexpr Node() = default;
            constexpr Node(T _data) noexcept: data(_data), next(nullptr) {}
            constexpr Node(T _data, Node* _next): data(_data), next(_next) {}
        };
        Node* head;
        size_t _size;
    public:
        using iter = Node*;
        using const_iter = const Node*;
        constexpr List() noexcept: head(nullptr), _size(0) {}
        constexpr List(List& list) = delete;
        constexpr List(List&& list) noexcept: head(list.head), _size(list._size) {}
        constexpr size_t size() { return _size; };
        constexpr void add(T elem, size_t index)
        {
            if (index > _size) {
                std::string error{};
                std::sprintf(&error[0], "IndexOutOfBounds(%lld)", index);
                throw std::range_error(error.c_str());
            }
            if (index == 0) {
                head = new Node(elem);
            } else {
                Node* node = head;
                while (index --> 1)
                    node = node->next;
                node->next = new Node(elem, node->next);
            }
            this->_size++;
        }
        constexpr void add(T elem) { add(elem, (_size)?_size: 0); }
        constexpr T get(size_t index) 
        {
            if (!head)
                throw std::runtime_error("Cannot get from an empty list!");
            else if (index < 0 || index >= _size)
                throw std::range_error("List Index Out of Bounds");
            Node* node = head;
            while (index --> 0 && !!node->next) node = node->next;
            return node->data;
        }
        constexpr T operator[](size_t index) { return this->get(index); }
        constexpr void operator+(List&& list) 
        {
            for (auto& elem: list)
                add(elem);
        }
    };
}

#endif