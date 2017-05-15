#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 
#include "GraphAdjacencyBase.hpp"

namespace cs202
{
	class AdjacencyList : public GraphAdjacencyBase 
	{
		LinearList<list<int> > AdjList;
		LinearList<list<pair<int,int> > > Adjlist;
		int vertices_;
	public:
		void resize(int vertices);
		int degree(int i);
    	bool edgeExists(int i, int j);
	    int vertices();
	    void add(int i, int j,int w);
	    void remove(int i, int j,int w);
	    void print();
	    Node<int> *getStart(int i);
	    Node<pair<int,int> > *getstart(int i);
	};
}
#endif 