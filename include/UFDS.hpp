#ifndef UFDS_
#define UFDS_ 

#include "seqLinearList.hpp"
#include "../lib/seqLinearList.cpp"

using namespace cs202;

namespace cs202 
{

  class UFDS 
  {
    class node 
    {
    public:
      int parent;
      int rank;
    };

    int size_;
    LinearList<int> set_size;
    LinearList<node> vertex;

  public:
    UFDS(const unsigned int& N);
    ~UFDS();
    void make_set (const unsigned int& N);
    int find_set (const unsigned int& x);
    void union_set (const unsigned int& x, const unsigned int& y);
    bool is_same_set (const unsigned int& x, const unsigned int& y);
    int num_disjoint_sets();
    int size_set (const unsigned int& x); 
    void link(const unsigned int &x,const unsigned int &y);
  };    
}

#endif  