#ifndef _SEQ_LINEAR_LIST
#define _SEQ_LINEAR_LIST 

#include <iostream>
#include <string.h>

namespace cs202 
{
    template<class T>
    class LinearList
    {
    private:
        T* buffer_;
        unsigned int size_;
        unsigned int capacity_;
    public:
        LinearList();
        LinearList(const int& isize);                   
        LinearList(const int& isize, const T& ival);    
        ~LinearList();                                  

        bool inRange(const int i);
        inline T& operator[](const int& i);         
        inline T at(const int& k);         
        void push_back(const T& item);              
        bool empty();                               
        unsigned int size();                                 
        unsigned int capacity();                                 
        void fill(const T& item);                   
        void resize(const int& n); 
        int find(const T& item);
        void erase(const T& item);
        void erase_pos(const int& pos);
        void insert(const T& item, const int& k);
        void print();
  };
}

#endif  /* _SEQ_LINEAR_LIST */

