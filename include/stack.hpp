#ifndef STACK_HPP_
#define STACK_HPP_

#include "list.hpp"

namespace cs202
{
  template<typename T>
    class stack
    {
    private:    
        Node<T> *start,*end;
        int size;
    public:
        stack();
        void push(const T& t);
        T pop();
        T top();
        int size_();
        inline bool empty();
        void print();
        ~stack();
    };
}

#endif