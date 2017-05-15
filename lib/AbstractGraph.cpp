#include "AbstractGraph.hpp"


void AbstractGraph :: dfsUtil(void (*work)(const int& ),const int &src = 0)
{
	stack<int> q;
	q.push(src);
	this->vis[src] = true;
	while(!q.empty())
	{
		int u = q.pop();

		this->time++;
		this->dfsTree[u].finishTime = time;
		work(u);
		this->vis[u] = true;

		if(this->degree(u) == 0)
			continue;

		if(this->type == List)
		{
			Node<int> *trav = this->AdjList.getStart(u);
			while(trav != NULL)
			{
				int v = trav->data;
				if(this->vis[v] == false)
				{
					this->vis[v] = true;
					this->dfsTree[v].discTime = time;
					this->dfsTree[v].pred = u;
					q.push(v);
				}
				trav = trav->next;
			} 
		}
		else
		{
			LinearList<int> trav = this->AdjMat.getAdjacent(u);
			for(int i=0;i<this->vertices_;i++)
			{
				if(trav[i] != INT_MAX)
				{
					int v = i;
					if(this->vis[v] == false)
					{
						this->dfsTree[v].discTime = time;
						this->dfsTree[v].pred = u;
						this->vis[v] = true;
						q.push(v);
					}
				}
			}
		}
	}
}
void AbstractGraph :: Dfs(void (*work)(const int& ),const int &src = 0)
{
	if(src >= this->vertices_)
		return ;

	this->dfsTree.resize(this->vertices_);
	this->time = 0;

	for(int i=0;i<vertices_;i++)
	{
		this->dfsTree[i].pred = -1;
		this->vis[i] = false;
	}
	dfsUtil(work,src);
	for(int i=0;i<this->vertices_;i++)
	{
		if(this->vis[i] == false)
		{
			dfsUtil(work,i);
		}
	}
}

void AbstractGraph :: bfsUtil(void (*work)(const int& ),const int &src = 0)
{
	queue<int> q;
	q.push(src);
	vis[src] = true;
	while(!q.empty())
	{
		int u = q.pop();

		this->vis[u] = true;
		work(u);
		if(this->degree(u) == 0)
			continue;

		if(this->type == List)
		{
			Node<int> *trav = this->AdjList.getStart(u);
			while(trav != NULL)
			{
				int v = trav->data;
				if(this->vis[v] == false)
				{
					this->bfsTree[v].pred = u;
					this->bfsTree[v].level = this->bfsTree[u].level+1;
					this->vis[v] = true;
					q.push(v);
				}
				trav = trav->next;
			} 
		}
		else
		{
			LinearList<int> trav = this->AdjMat.getAdjacent(u);
			for(int i=0;i<this->vertices_;i++)
			{
				if(trav[i] == INT_MAX)
				{
					int v = i;
					if(this->vis[v] == false)
					{
						this->bfsTree[v].pred = u;
						this->bfsTree[v].level = this->bfsTree[u].level+1;
						this->vis[v] = true;
						q.push(v);
					}
				}
			}
		}
	}
}

void AbstractGraph :: Bfs(void (*work)(const int& ),const int &src = 0)
{
	if(src >= this->vertices_)
		return ;

	this->bfsTree.resize(this->vertices_);
	this->time = 0;

	for(int i=0;i<this->vertices_;i++)
	{
		this->vis[i] = false;
		this->bfsTree[i].pred = -1;
		this->bfsTree[i].level = 0;
	}

	bfsUtil(work,src);
	for(int i=0;i<this->vertices_;i++)
	{
		if(this->vis[i] == false)
		{
			bfsUtil(work,i);
		}
	}
}

void empty(const int &i)
{

}

LinearList<dfsNode> AbstractGraph :: getDFSTree(const int &src)
{
	if(src >= this->vertices_)
		return dfsTree;

	this->dfsTree.resize(this->vertices_);
	this->time = 0;

	for(int i=0;i<vertices_;i++)
	{
		this->dfsTree[i].pred = -1;
		this->vis[i] = false;
	}
	dfsUtil(&empty,src);

	return dfsTree;
}

LinearList<bfsNode> AbstractGraph :: getBFSTree(const int &src)
{
	if(src >= this->vertices_)
		return bfsTree;

	this->bfsTree.resize(this->vertices_);
	this->time = 0;

	for(int i=0;i<this->vertices_;i++)
	{
		this->vis[i] = false;
		this->bfsTree[i].pred = -1;
		this->bfsTree[i].level = 0;
	}

	bfsUtil(&empty,src);

	return bfsTree;
}


LinearList<Edge> AbstractGraph :: KruskalMST()
{
	LinearList<Edge> ret;
	assert(this->type == List);

	MinPriorityQueue<Edge> queue;

	Edge temp;

	UFDS set(this->vertices_);

	for(int i=0;i<this->vertices_;i++)
	{
		set.make_set(i);
		Node<pair<int,int> > *trav = this->AdjList.getstart(i);
		temp.src = i;
		while(trav)
		{
			temp.des = trav->data.first;
			temp.weight = trav->data.second;
			queue.insert(temp);
			trav = trav->next;
		}
	}

	while(!queue.empty())
	{
		temp = queue.extract_min();
		if(set.find_set(temp.src) != set.find_set(temp.des))
		{
			ret.push_back(temp);
			set.union_set(temp.src,temp.des);
		}
	}

	return ret;
}

LinearList<Edge> AbstractGraph :: PrimsMST()
{
	LinearList<Edge> ret;
	Edge edges;

	MinPriorityQueue<pair<int,int> > queue;
	queue.insert(make_pair(0,0));

	LinearList<int> s;
	s.resize(this->vertices_);
	for(int i=0;i<this->vertices_;i++)
	{
		s[i] = 0;
	}

	while(!queue.empty())
	{
		pair<int,int> temp = queue.extract_min();
		int u = temp.second;
		if(s[u] == 1)
			continue;
		s[u] = 1;
		Node<pair<int,int> > *trav = this->AdjList.getstart(u);
		while(trav)
		{
			int v = trav->data.first;
			if(s[v] == 0)
			{
				temp.first = trav->data.second;
				temp.second = v;
				queue.insert(temp);
				edges.src = u,edges.des = v,edges.weight = temp.first;
				ret.push_back(edges);
			}
			trav = trav->next;
		}
	}

	ret = KruskalMST();
	return ret;
}