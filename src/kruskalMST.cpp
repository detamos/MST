#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "UndirectedGraph.hpp"
#include "../lib/UndirectedGraph.cpp"

using namespace cs202;
using namespace std;

int getLines(char *);

void print(const int &i)
{
	cout<<i<<" ";
}

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		cerr<<"Wrong number of arguments\n";
		return 0;
	}

	int size;
	char ch;

	if(argc == 3)
	{
		size = getLines(argv[1]);
		ch = argv[2][0];
	}
	else
	{
		cin>>size;
		ch = argv[1][0];
	}

	int mat[size][size];

	if(argc == 3)
	{
		ifstream inFile;
		inFile.open(argv[1]);

		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				inFile>>mat[i][j];
			}
		}
	}
	else
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cin>>mat[i][j];
			}
		}
	}

	UndirectedGraph graph(size,ch);

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(mat[i][j] != INT_MAX && mat[i][j])
			{
				graph.add(i,j,mat[i][j]);
			}
		}
	}

	graph.print();

	while(1)
	{
		cout<<endl;
		cout<<"1.Add a new Edge.\n";
		cout<<"2.Delete an edge.\n";
		cout<<"3.Check if an edge exists.\n";
		cout<<"4.Run bfs.\n";
		cout<<"5.Run dfs.\n";
		cout<<"6.Graph Info.\n";
		cout<<"7.Kruskal MST.\n";
		cout<<"8.Prims MST.\n";
		cout<<"9.Exit\n";

		int choice,src,des,w;
		cout<<"Enter your choice : ";
		cin>>choice;
		LinearList<Edge> mst;
		switch(choice)
		{
		case 1:
			cout<<"Enter source      : ";
			cin>>src;
			cout<<"Enter destination : ";
			cin>>des;
			cout<<"Enter Weight      : ";
			cin>>w;
			graph.add(src,des,w);
		break;
		case 2:
			cout<<"Enter source      : ";
			cin>>src;
			cout<<"Enter destination : ";
			cin>>des;
			cout<<"Enter Weight      : ";
			cin>>w;
			graph.remove(src,des,w);
		break;
		case 3:
			cout<<"Enter source      : ";
			cin>>src;
			cout<<"Enter destination : ";
			cin>>des;
			if(graph.edgeExists(src,des))
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		break;
		case 4:
			cout<<"Source : ";
			cin>>src;
			graph.bfs(&print,src);
		break;
		case 5:
			cout<<"Source : ";
			cin>>src;
			graph.dfs(&print,src);
		break;
		case 6:
			graph.print();
		break;
		case 7:
			mst = graph.kruskalMST();
			mst.print();
			break;
		case 8:
			mst = graph.primsMST();
			mst.print();
			break;
		case 9:
			return 0;
		default: 
			cout<<"Wrong choice.\n";
		}

	}

	return 0;
}

int getLines(char *file)
{
	string command = "wc -l ";
	command += file;
	command += " > output";
	system(command.c_str());
	ifstream infile;
	infile.open("output");
	int ret;
	infile>>ret;
	infile.close();
	system("rm output");
	return ret;
}