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
	while(q--)
	{
		cin>>x>>y;
		bool flag = false;
		for(int i=0;i<mst.size();i++)
		{
			if((mst[i].src == x && mst[i].des == y)
				|| (mst[i].src == y && mst[i].des == x))
			{
				cout<<"yes\n";
				flag = true;
				break;
			}
		}
		if(flag == false)
			cout<<"no\n";
	}
	return 0;
}