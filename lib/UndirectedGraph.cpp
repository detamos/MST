#include "UndirectedGraph.hpp"

UndirectedGraph :: UndirectedGraph(int vertices,char mode = 'm')
{
	this->vertices_ = vertices;
	vis.resize(vertices_);
	if(mode == 'l')
	{
		this->AdjList.resize(vertices);
		this->type = List;
	}
	else
	{
		this->AdjMat.resize(vertices);
		this->type = Matrix;
	}
}

bool UndirectedGraph :: edgeExists(int i,int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
			return false;

	if(this->type == List)
	{
		return this->AdjList.edgeExists(i,j);
	}
	else
	{
		return this->AdjMat.edgeExists(i,j);
	}
}

int UndirectedGraph :: degree(int i)
{
	if(i >= this->vertices_)
		return -1;
	
	if(this->type == List)
	{
		return this->AdjList.degree(i);
	}
	else
	{
		return this->AdjMat.degree(i);
	}
}

int UndirectedGraph :: edges()
{
	int edge = 0;
	for(int i=0;i<vertices_;i++)
		edge += this->degree(i);
	return edge/2;
}
int UndirectedGraph :: vertices()
{
	return this->vertices_;
}
void UndirectedGraph :: add(int i, int j,int w)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	if(this->edgeExists(i,j))
		return ;
	if(this->type == List)
	{
		this->AdjList.add(i,j,w);
		this->AdjList.add(j,i,w);
	}
	else
	{	
		this->AdjMat.add(i,j,w);
		this->AdjMat.add(j,i,w);
	}
}
void UndirectedGraph :: remove(int i, int j,int w)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	if(this->type == List)
	{	
		this->AdjList.remove(i,j,w);
		this->AdjList.remove(j,i,w);
	}
	else
	{
		this->AdjMat.remove(i,j,w);
		this->AdjMat.remove(j,i,w);
	}
}

void UndirectedGraph :: print()
{
	cout<<"Vertices : "<<this->vertices_<<" ";
	cout<<"Edges : "<<this->edges()<<endl;
//	if(this->type == List)
//	{
//		this->AdjList.print();
//	}
//	else
///	{
//		this->AdjMat.print();
//	}
}

void UndirectedGraph :: bfs(void (*work)(const int&),const int &src = 0)
{
	this->Bfs(work,src);
}

void UndirectedGraph :: dfs(void (*work)(const int&),const int &src = 0)
{
	this->Dfs(work,src);
}

LinearList<dfsNode> UndirectedGraph :: getDFStree(const int &src = 0)
{
	return this->getDFSTree(src);
}

LinearList<bfsNode> UndirectedGraph :: getBFStree(const int &src = 0)
{
	return this->getBFSTree(src);
}

LinearList<Edge> UndirectedGraph :: kruskalMST()
{
	return this->KruskalMST();
}

LinearList<Edge> UndirectedGraph :: primsMST()
{
	return this->PrimsMST();
}