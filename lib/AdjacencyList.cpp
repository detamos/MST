#include "AdjacencyList.hpp"

void AdjacencyList :: resize(int vertices)
{
	this->vertices_ = vertices;
	this->AdjList.resize(vertices);
	this->Adjlist.resize(vertices);
}

bool AdjacencyList :: edgeExists(int i,int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
			return false;

	if(this->AdjList[i].exists(j))
		return true;
	return false;
}

int AdjacencyList :: degree(int i)
{
	if(i >= this->vertices_)
		return -1;
	
	return this->AdjList[i].length();
}

int AdjacencyList :: vertices()
{
	return this->vertices_;
}
void AdjacencyList :: add(int i, int j,int w)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	if(this->edgeExists(i,j))
		return ;
	this->AdjList[i].append(j);
	this->Adjlist[i].append(make_pair(j,w));
}
void AdjacencyList :: remove(int i, int j,int w)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	this->AdjList[i].remove(j);
	this->Adjlist[i].remove(make_pair(j,w));
}


void AdjacencyList :: print()
{
//	for(int i=0;i<this->vertices_;i++)
//	{
//		cout<<i<<" : ";
//		this->AdjList[i].print();
//	}
}

Node<int>* AdjacencyList :: getStart(int i)
{
	return this->AdjList[i].getStart();
}

Node<pair<int,int> > * AdjacencyList :: getstart(int i)
{
	return this->Adjlist[i].getStart();
}