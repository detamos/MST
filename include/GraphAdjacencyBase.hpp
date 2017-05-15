#ifndef GRAPH_ADJACENCY_BAG
#define GRAPH_ADJACENCY_BAG


#include "seqLinearList.hpp"
#include "list.hpp"
#include "../lib/seqLinearList.cpp"
#include "../lib/list.cpp"

using namespace cs202;

namespace cs202
{
	class GraphAdjacencyBase 
	{
	  virtual bool edgeExists(int i, int j) = 0;
	  virtual int vertices() = 0;
	  virtual void add(int i, int j,int w) = 0;
	  virtual void remove(int i, int j,int w) = 0;
	  virtual int degree(int i) = 0;
	};
}
#endif 