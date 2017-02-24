#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<list>
#include<queue>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

class Graph
{
	private:
		int V;
		vector<list<pair<int,int>> >  edgeList;
		struct comparePair
		{
			bool operator() (const pair<int,int> p1, const pair<int,int> p2) const
			{
				return( p2.second < p1.second);
			}
		};
	public:
		Graph(int V);
		void addEdge(int src, int dest, int weight);
		void printMST(vector<int> parent, vector<int> key);
		void primMST();


};

Graph::Graph(int V)
{
	this->V = V;
	edgeList.assign(V,list<pair<int,int>>(0,make_pair(0,0)));
}

void Graph::addEdge(int src, int dest, int weight)
{
	edgeList[src].push_back(make_pair(dest,weight));
	edgeList[dest].push_back(make_pair(src,weight));
}


void Graph::printMST(vector<int> parent, vector<int> key)
{
	int N = parent.size();
	for(int i=0; i< N; ++i)
		if( parent[i] != i)
			cout<<"Node: "<<i<<" --- "<<parent[i]<<"\t Weight: "<<key[i]<<endl;	
}

void Graph::primMST()
{
	priority_queue < pair<int,int>, vector<pair<int,int>>, comparePair> pq;
	vector<int> parent (V,-1);
	vector<int> key (V,INT_MAX);
	vector<bool> mstSet(V,false);
	key[0] = 0;
	parent[0] = 0;
	pq.push(make_pair(0,0));

	while( !pq.empty())
	{	
		int u = pq.top().first;
		pq.pop();
		if( !mstSet[u])
		{
			mstSet[u] = true;	
			for(list<pair<int,int>>::iterator it= edgeList[u].begin(); it!= edgeList[u].end();++it)
			{
				int v = (*it).first;
				if( !mstSet[v] &&  (*it).second < key[v] )
				{
					parent[v] = u;
					key[v] = (*it).second;
					pq.push(make_pair(v,key[v]));
				}	
			}
		}
	}

	printMST(parent, key);
}


int main()
{

	int V = 9;
    Graph g(V);
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.primMST();
}

