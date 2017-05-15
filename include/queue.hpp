#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "list.hpp"

namespace cs202
{
  template <class T>
    class queue
    {
    private:
        Node<T> *start,*end;
        int size;
      public:
        queue();
        void push(const T& t);
        T pop();
        T front();
        inline int size_();
        inline bool empty();
        void print();
        ~queue();
    };
}
#endif