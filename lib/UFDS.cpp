#include "UFDS.hpp"

using namespace cs202;

UFDS :: UFDS(const unsigned int &N)
{
	this->vertex.resize(N);
	this->size_ = N;
	set_size.resize(N);
}

UFDS :: ~UFDS()
{

}

void UFDS :: make_set(const unsigned int &N)
{
	this->vertex[N].parent = N;
	this->vertex[N].rank = 0;
	set_size[N] = 1;
}

int UFDS :: find_set(const unsigned int &x)
{
	if(x != this->vertex[x].parent)
		this->vertex[x].parent = find_set(this->vertex[x].parent);
	return this->vertex[x].parent;
}

void UFDS :: union_set(const unsigned int &x,const unsigned int &y)
{
	if(is_same_set(x,y) == false)
		this->size_--;
	this->link(this->find_set(x),this->find_set(y));
}

void UFDS :: link(const unsigned int &x,const unsigned int &y)
{
	if(this->vertex[x].rank > this->vertex[y].rank)
	{
		this->vertex[y].parent = x;
		this->set_size[x]++;
	}
	else
	{
		this->set_size[y]++;
		this->vertex[x].parent = y;
		if(this->vertex[x].rank == this->vertex[y].rank)
			this->vertex[y].rank ++;
	}
}

bool UFDS :: is_same_set(const unsigned int &x,const unsigned int& y)
{
	return (this->find_set(x) == this->find_set(y));
}

int UFDS :: num_disjoint_sets()
{
	return this->size_;
}

int UFDS :: size_set(const unsigned int &x)
{
	return this->set_size[find_set(x)];
}