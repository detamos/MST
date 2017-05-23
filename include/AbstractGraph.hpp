#ifndef ABSTRACT_GRAPH
#define ABSTRACT_GRAPH 

#include "queue.hpp"
#include "stack.hpp"
#include "../lib/queue.cpp"
#include "../lib/stack.cpp"
#include "AdjacencyMatrix.hpp"
#include "../lib/AdjacencyMatrix.cpp"
#include "AdjacencyList.hpp"
#include "../lib/AdjacencyList.cpp"
#include "UFDS.hpp"
#include "../lib/UFDS.cpp"
#include "priorityQueue.hpp"
#include "../lib/priorityQueue.cpp"
#include <assert.h>

#include <iostream>

using namespace std;
using namespace cs202;

enum GraphType{List,Matrix};

namespace cs202
{
  class dfsNode
  {
  public: 
    int pred;
    int discTime;
    int finishTime;
  };

  class bfsNode
  {
  public:
    int pred;
    int level;
  };

  class Edge
  {
  public:
    int src;
    int des;
    int weight;
    bool operator == (const Edge &e)
    {
      return ((this->src == e.src) && (this->des == e.des) && (this->weight && e.weight));
    }
    Edge &operator = (const Edge &e)
    {
      this->src = e.src;
      this->des = e.des;
      this->weight = e.weight;
    }
    bool operator < (const Edge &e)
    {
      return (this->weight < e.weight);
    }
    bool operator > (const Edge &e)
    {
      return (this->weight > e.weight);
    }
    friend ostream &operator << (ostream &output,const Edge &e)
    {
      output<<"("<<e.src<<","<<e.des<<","<<e.weight<<")";
      return output;
    }
  };

  template<typename T,typename F>
  class Pair
  {
  public:
    T first;
    F second;
    bool operator < (const Pair & temp)
    {
      return (this->second < temp.second);
    }
    bool operator > (const Pair &temp)
    {
      return (this->second > temp.second);
    }
    Pair& operator = (const Pair &temp)
    {
      this->first = temp.first;
      this->second = temp.second;
    }
    friend ostream &operator << (ostream &output,const Pair &temp)
    {
      output<<"("<<temp.first<<","<<temp.second<<")";
      return output;
    }
  };

  template<typename T,typename F>
  Pair<T,F> makepair(const T &t,const F &f)
  {
    Pair<T,F> temp;
    temp.first = t;
    temp.second = f;
    return temp;
  }

  class AbstractGraph 
  {
  protected:
    AdjacencyMatrix AdjMat;
    AdjacencyList AdjList;
    int vertices_;
    LinearList<bool> vis;
    LinearList<dfsNode> dfsTree;
    LinearList<bfsNode> bfsTree;
    int time;
  protected:
    GraphType type;
  public:
    virtual ~AbstractGraph(){}
    virtual bool edgeExists(int i, int j) = 0;
    virtual int edges() = 0;
    virtual int vertices() = 0;
    virtual void add(int i, int j,int w) = 0;
    virtual void remove(int i, int j,int w) = 0;
    virtual int degree(int i) = 0;
    void dfsUtil(void (*work)(const int& ),const int &src);
    void Dfs(void (*work)(const int&),const int &src);
    void bfsUtil(void (*work)(const int&),const int &src);
    void Bfs(void (*work)(const int&),const int &src);
    LinearList<dfsNode> getDFSTree(const int &src);
    LinearList<bfsNode> getBFSTree(const int &src);
    LinearList<Edge> KruskalMST();
    LinearList<Edge> PrimsMST();
  };
}
#endif