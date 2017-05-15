#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 
#include "GraphAdjacencyBase.hpp"

namespace cs202
{
	class AdjacencyMatrix : public GraphAdjacencyBase 
	{
		LinearList<LinearList<int> > AdjMat;
		int vertices_;
	public:
		void resize(int vertices);
		int degree(int i);
    	bool edgeExists(int i, int j);
	    int vertices();
	    void add(int i, int j,int w);
	    void remove(int i, int j,int w);
	    void print();
	    LinearList<int> getAdjacent(int i);
	};
}
#endif 