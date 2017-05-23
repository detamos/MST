#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "UndirectedGraph.hpp"
#include "../lib/UndirectedGraph.cpp"

using namespace cs202;
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int x,y,c;
	UndirectedGraph graph(n,'l');
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>c;
		graph.add(x,y,c);
	}
	int q;
	cin>>q;
	LinearList<Edge> mst = graph.kruskalMST();
	int parent[mst.size()];
	for(int i=0;i<mst.size();i++)
	{
		int u = mst[i].src;
		int v = mst[i].des;
		if(parent[u] == -1)
			parent[u] = v;
		else
			parent[v] = u;
		cout<<u<<" "<<v<<endl;
	}
	cout<<endl;
	int ctr = 0;
	while(q--)
	{
		cin>>x>>y;
		cout<<x<<" "<<y<<endl;
		if(x >= n || y >= n)
		{
			cout<<"no\n";
			continue;
		}
		if(parent[x] == y || parent[y] == x)
		{
			cout<<"yes\n";
			ctr++;
		}
		else
			cout<<"no\n";
	}
	cout<<ctr<<endl;
	return 0;
}