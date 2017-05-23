// Purpose: Assignment - 06 (DSA CS202)
// Author: Deepanshu Tyagi (B15311)
// Date of Creation: 22th,Arpil 2017
// Bugs:

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1

#include "seqLinearList.hpp"
#include <limits.h>
#include <assert.h>

using namespace cs202;

namespace cs202{
 	
 	template<class T>
 	class MinPriorityQueue{
		
		LinearList<T> heap;
 		int heap_size_;
 		void heapify(const size_t& pos);
 		inline int parent(const size_t& pos);
 		inline int left(const size_t& pos);
 		inline int right(const size_t& pos);

 	public:
 		MinPriorityQueue();
 		MinPriorityQueue(LinearList<T>& v);
 		void insert(const T& a);
 		inline T minimum();
 		T extract_min();
 		inline int heap_size();
 		void build_heap(LinearList<T>& v);
 		inline bool empty();
 		void heap_decrease_key(const size_t& pos,const T &key);
 		void print();
 	};
} 	
#endif 