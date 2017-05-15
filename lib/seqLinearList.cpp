#ifndef SEQ_LINEAR_LIST
#define SEQ_LINEAR_LIST
#include "seqLinearList.hpp"
#include <iostream>

using namespace std;
using namespace cs202;

template<class T>
LinearList<T> :: LinearList()
{
	size_ = 0;
	buffer_ = new T[(int)1e3+1];
	capacity_ = 1e3+1;
}

template<class T>
LinearList<T> :: LinearList(const int& isize)
{
	capacity_ = isize;
	buffer_ = new T[isize];
	for(int i=0;i<isize;i++)
		buffer_[i] = 0;
	size_ = 0;
}

template<class T>
LinearList<T> :: LinearList(const int& isize,const T &ival)
{
	capacity_ = isize;
	buffer_ = new T[isize];
	for(int i=0;i<isize;i++)
		buffer_[i] = ival;
	size_ = 0;
}

template<class T>
void LinearList<T> :: resize(const int &n)
{
	if(n > capacity_)
	{
		cout<<"Error seqLinearList :: n > capacity_\n";
		return ;
	}
	if(size_ == 0)
	{
		buffer_ = new T[n];
	}
	else
	{
		T *temp = new T[n];
		for(int i=0;i<size_;i++)
			temp[i] = buffer_[i];
		delete[] buffer_;
		buffer_ = temp;
	}
	size_ = n;
}

template<class T>
LinearList<T> :: ~LinearList()
{
	//if(size_)
		//delete buffer_;
}

template<class T>
bool LinearList<T> :: inRange(const int i)
{
	//return true;
	return (i<size_ && i >= 0);
}

template<class T>
inline T& LinearList<T> :: operator[](const int &i)
{
	if(!inRange(i))
	{
		cout<<"Error seqLinearList :: inRange(operato[]) = false "<<i<<"\nReturning first Element\n";
		return buffer_[0];
	}
	return buffer_[i];
}

template<class T>
bool LinearList<T> :: empty()
{
	return (size_ == 0);	
}

template<class T>
unsigned int LinearList<T> :: size()
{
	return size_;
}

template<class T>
unsigned int LinearList<T> :: capacity()
{
	return capacity_;
}

template<class T>
inline T LinearList<T> :: at(const int &k)
{
	if(!inRange(k-1))
	{
		cout<<"Error seqLinearList :: inRange = false "<<"\nReturning first Element\n";
		return buffer_[0];
	}
	return buffer_[k-1];
}

template<class T>
void LinearList<T> :: push_back(const T &item)
{
	if(this->size_ == capacity_)
	{
		cout<<"Error seqLinearList :: push_back(list full)\n";
		return ;
	}
	buffer_[this->size_] = item;
	this->size_++;
}

template<class T>
void LinearList<T> :: fill(const T& item)
{
	for(int i=0;i<size_;i++)
	{
		buffer_[i] = item;
	}
}

template<class T>	
int LinearList<T> :: find(const T& item)
{
	for(int i=0;i<size_;i++)
	{
		if(item == buffer_[i])
			return i;
	}
	return size_;
}

template<class T>
void LinearList<T> :: erase(const T& item)
{
	int count = 0;
	for(int i=0;i<size_;i++)
	{
		if(buffer_[i] == item)
		{
			count++;
		}
	}
	for(int j=0;j<count;j++)
	{
		for(int i=0;i<size_;i++)
		{
			if(buffer_[i] == item)
			{
				swap(buffer_[i],buffer_[i+1]);
			}
		}	
		size_--;
	}
}

template<class T>
void LinearList<T> :: erase_pos(const int &pos)
{
	if(!inRange(pos-1))
	{
		cout<<"Error seqLinearList :: inRange = false ";
		return ;
	}
	for(int i=pos-1;i<size_;i++)
	{
		buffer_[i] = buffer_[i+1];
	}
	size_--;
}

template<class T>
void LinearList<T> :: insert(const T& item,const int &k)
{
	if(size_ == capacity_)
	{
		cout<<"Error seqLinearList :: insert : List is Full\n";
		return ;
	}
	if(k < 0 || k > size_)
	{
		cout<<"Error seqLinearList :: insert : Wrong Index\n";
		return ;
	}
	buffer_[size_] = item;
	for(int i=size_;i>k;i--)
	{
		swap(buffer_[i],buffer_[i-1]);
	}
	size_++;
}

template<class T>
void LinearList<T> :: print()
{
	for(int i=0;i<this->size_;i++)
		cout<<buffer_[i]<<" ";
	cout<<endl;
}
#endif