#include "list.hpp"
#include <iostream>

using namespace std;
using namespace cs202;

template<class T>
list<T>::list()
{
    this->start = this->end = NULL;
    this->size = 0;
}

template<class T>
list<T>::~list()
{
    Node<T> *temp = this->start;
    while(temp)
    {
        Node<T> *del = temp;
        temp = temp->next;
        delete[] del;
        this->size = 0;
    }
}

template<class T>
list<T> :: list(const list<T> &x)
{
    if(x.size == 0)
        return;
    Node<T> *trav = x.start,*prev = NULL;
    while(trav)
    {
        Node<T> *temp = new Node<T>;
        temp->data = trav->data;
        temp->next = NULL;
        if(this->size == 0)
        {
            this->start = this->end = temp;
            prev = temp;
            (this->size) ++;
        }
        else
        {
            prev->next = temp;
            prev = temp;
            this->end = temp;
            (this->size) ++;
        }
        trav = trav->next;
    }
}

template<class T>
bool list<T> :: exists(const T &value)
{
    if(this->start == NULL)
        return false;
    Node<T> *trav = this->start;
    while(trav)
    {
        if(trav->data == value)
            return true;
        trav = trav->next;
    }
    return false;
}

template<class T>
void list<T>::append(const T& value)
{
    Node<T> *temp = new Node<T>;
    if(temp == NULL)
        return ;
    temp->data = value;
    temp->next = NULL;
    if(this->size == 0)
    {
        this->start = this->end = temp;
        (this->size)++;
    }
    else
    {
        this->end->next = temp;
        this->end = temp;
        (this->size)++;
    }
}

template<class T>
inline int list<T>::length()
{
    return (this->size);
}

template<class T>
inline bool list<T>::empty()
{
    return (this->size == 0);
}

template<class T>
void list<T>::cons(const T& value)
{
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->next = NULL;
    if(this->start == NULL)
    {
        this->start = temp;
        (this->size) ++;
        return ;
    }
    temp->next = (this->start);
    this->start = temp;
    (this->size)++;
}

template<class T>
void list<T>::remove(const T &x)
{
    Node<T> *trav = this->start,*prev = NULL;
    while(trav)
    {
        if(trav->data == x)
        {
            break;
        }
        prev = trav;
        trav = trav->next;
    }  
    if(prev == NULL)
    {
        Node<T> *temp = this->start;
        this->start = this->start->next;
        delete[] temp;
        (this->size)--;
    }
    else
    {
        prev->next = trav->next;
        (this->size)--;
        trav->next = NULL;
        delete[] trav;
    }
}

template<class T>
void list<T>::append(list<T> &x)
{
    if(x.size == 0)
        return;
    Node<T> *trav = x.start;
    while(trav)
    {
        append(trav->data);
        trav = trav->next;
    }
}

template<class T>
void list<T>::print()
{
    Node<T> *temp = this->start;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
Node<T>* list<T> :: getStart()
{
    return this->start;
}