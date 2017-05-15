#ifndef LIST_HPP
#define LIST_HPP 1

namespace cs202
{
    template<class T>
    class Node
    {
    public:
        T data;
        Node<T> *next;
    };

    template<class T>
    class list
    {
    public:
        Node<T> *start,*end;
        int size;
    public:
        list();
        list(const list<T> & x);
        ~list();
        Node<T>* getStart();
        bool exists(const T &value);
        void append(const T& value);
        inline int length();
        inline bool empty();
        void cons(const T& value);
        void remove(const T & x);
        void append(list<T>& x);
        void print();
        T &operator[](const int &i);
    };
 }

#endif