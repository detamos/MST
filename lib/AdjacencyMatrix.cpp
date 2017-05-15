#include "AdjacencyMatrix.hpp"
#include <limits.h>

void AdjacencyMatrix :: resize(int vertices)
{
	this->vertices_ = vertices;
	this->AdjMat.resize(vertices);
	for(int i=0;i<vertices;i++)
		this->AdjMat[i].resize(vertices);

	for(int i=0;i<vertices;i++)
		for(int j=0;j<vertices;j++)
			this->AdjMat[i][j] = INT_MAX;
}

bool AdjacencyMatrix :: edgeExists(int i,int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
			return false;

	if(this->AdjMat[i][j] != INT_MAX)
		return true;
	return false;
}

int AdjacencyMatrix :: degree(int i)
{
	if(i >= this->vertices_)
		return -1;
	
	int deg = 0;
	for(int j=0;j<this->vertices_;j++)
		if(this->AdjMat[i][j] != INT_MAX)
			deg++;
	return deg;
}

int AdjacencyMatrix :: vertices()
{
	return this->vertices_;
}
void AdjacencyMatrix :: add(int i, int j,int w)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	if(this->edgeExists(i,j))
		return ;
	
	this->AdjMat[i][j] = w;
}
void AdjacencyMatrix :: remove(int i, int j,int w)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	this->AdjMat[i][j] = INT_MAX;
}


void AdjacencyMatrix :: print()
{
//	for(int i=0;i<this->vertices_;i++)
//	{
//		for(int j=0;j<this->vertices_;j++)
//			cout<<this->AdjMat[i][j]<<" ";
//		cout<<endl;
//	}
}

LinearList<int> AdjacencyMatrix :: getAdjacent(int i)
{
	return this->AdjMat[i];
}