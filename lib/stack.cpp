#include "list.hpp"
#include "stack.hpp"
#include <iostream>
#include <limits.h>

using namespace std;
using namespace cs202;

template<class T>
stack<T>::stack()
{
	this->start = this->end = NULL;
	this->size = 0;
}

template<class T>
stack<T>::~stack()
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
void stack<T>::push(const T &value)
{ 
	 Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->next = NULL;
    if(this->start == NULL)
    {
        this->start = temp;
        (this->size)++;
        return ;
    }
    temp->next = (this->start);
    this->start = temp;
    (this->size)++;
}

template<class T>
T stack<T>::pop()
{
	if(this->size == 0)
		return INT_MAX;
	int ret = this->start->data;
	Node<T> *temp = this->start;
	this->start = this->start->next;
	if(this->size == 1)
		this->end = NULL;
	temp->next = NULL;
	delete[] temp;
	(this->size)--;
	return ret;
}

template<class T>
T stack<T>::top()
{
	return (this->start->data);
}

template<class T>
int stack<T>:: size_()
{
	return (this->size);
}

template<class T>
inline bool stack<T>::empty()
{
	return (this->size == 0);
}

template<class T>
void stack<T>::print()
{
	Node<T> *temp = this->start;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}