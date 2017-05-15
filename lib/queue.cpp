#include "queue.hpp"
#include <iostream>
#include <limits.h>

using namespace std;
using namespace cs202;


template<class T>
queue<T>::queue()
{
	this->start = this->end = NULL;
	this->size = 0;
}

template<class T>
queue<T>::~queue()
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
void queue<T>::push(const T& value)
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
        (this->size) ++;
    }
}

template<class T>
T queue<T>::pop()
{
	if(this->size <= 0)
		return INT_MAX;
	int ret = this->start->data;
	Node<T> *temp = this->start;
	this->start = this->start->next;
	if(this->size == 1)
		this->end = this->start = NULL;
	temp->next = NULL;
	delete[] temp;
	this->size--;
	return ret;
}

template<class T>
T queue<T>::front()
{
	return (this->start->data);
}

template<class T>
inline int queue<T>::size_()
{
	return (this->size);
}

template<class T>
inline bool queue<T>::empty()
{
	return (this->size == 0);
}

template<class T>
void queue<T>::print()
{
	Node<T> *temp = this->start;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}