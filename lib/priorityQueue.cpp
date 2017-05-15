#include "../lib/seqLinearList.cpp"
#include "priorityQueue.hpp"
#include <iostream>

using namespace std;
using namespace cs202;


template<class T>
inline int MinPriorityQueue<T> :: parent(const size_t &pos)
{
	return (pos-1)/2;
}

template<class T>
inline int MinPriorityQueue<T> :: left(const size_t &pos)
{
	return (2*pos)+1;
}

template<class T>
inline int MinPriorityQueue<T> :: right(const size_t &pos)
{
	return (2*pos)+2;
}

template<class T>
MinPriorityQueue<T> :: MinPriorityQueue()
{
	//this->heap.LinearList(1e6+1);
	this->heap_size_ = 0;
}

template<class T>
MinPriorityQueue<T> :: MinPriorityQueue(LinearList<T> &v)
{
	this->build_heap(v);
}

template<class T>
void MinPriorityQueue<T> :: heapify(const size_t &pos)
{
	int l = this->left(pos),r = this->right(pos);
	int swap_pos = pos;
	if(l < this->heap_size_ && heap[l] < heap[swap_pos])
		swap_pos = l;
	if(r < this->heap_size_ && heap[r] < heap[swap_pos])
		swap_pos = r;
	if(swap_pos == pos)
		return;
	swap(heap[pos],heap[swap_pos]);
	heapify(swap_pos);
}

template<class T>
void MinPriorityQueue<T> :: insert(const T &a)
{
	if(this->heap_size_ == this->heap.capacity())
	{
		cerr<<"OVERFLOW priorityQueue :: insert()\n";
		return ;
	}
	this->heap_size_++;
	int size = this->heap_size_-1;
	this->heap.push_back(a);

	while(size != 0 && this->heap[size] < this->heap[parent(size)])
	{
		swap(this->heap[size],this->heap[parent(size)]);
		size = parent(size);
	}
}

template<class T>
void MinPriorityQueue<T> :: heap_decrease_key(const size_t &pos,const T &key)
{
	if(pos >= this->heap_size_)
		return;
	this->heap[pos] = key;
	int i = pos;
	while(i != 0 && this->heap[i] < this->heap[parent(i)])
	{
		swap(this->heap[i],this->heap[parent(i)]);
		i  = parent(i);
	}
}

template<class T>
inline T MinPriorityQueue<T> :: minimum()
{
	if(this->heap_size_)
		return this->heap[0];
	return (T)NULL;
}

template<class T>
T MinPriorityQueue<T> :: extract_min()
{
	T ret = this->heap[0];
	this->heap[0] = this->heap[this->heap_size_-1];
	this->heap_size_--;
	this->heapify(0);
	return ret;
}

template<class T>
inline int MinPriorityQueue<T> :: heap_size()
{
	return this->heap_size_;
}

template<class T>
void MinPriorityQueue<T> :: build_heap(LinearList<T> &v)
{
	int n = v.size();
	this->heap_size_ = 0;
	for(int i=0;i<n;i++)
	{
		this->heap.push_back(v[i]);
		this->heap_size_++;
	}
	for(int i=n/2;i>=0;i--)
	{
		heapify(i);
	}	
}

template<class T>
inline bool MinPriorityQueue<T> :: empty()
{
	return (this->heap_size_ == 0);
}

template<class T>
void MinPriorityQueue<T> :: print()
{
	for(int i=0;i<this->heap_size_;i++)
		cout<<this->heap[i]<<" ";
	cout<<endl;
}