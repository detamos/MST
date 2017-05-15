#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 

#include "AbstractGraph.hpp"
#include "../lib/AbstractGraph.cpp"

using namespace cs202;

namespace cs202
{
  class UndirectedGraph : AbstractGraph 
  {
  public:
    UndirectedGraph(int vertices,char mode);
    int degree(int i);
    bool edgeExists(int i, int j);
    int edges();
    int vertices();
    void add(int i, int j,int w);
    void remove(int i, int j,int w);
    void print();
    void bfs(void (*work)(const int&),const int &src);
    void dfs(void (*work)(const int&),const int &src);
    LinearList<dfsNode> getDFStree(const int &src);
    LinearList<bfsNode> getBFStree(const int &src);
    LinearList<Edge> kruskalMST();
    LinearList<Edge> primsMST();
  };
}
#endif 