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
		struct edge
		{
			int src;
			int dest;
			int weight;
			edge(int src=0, int dest=0, int weight = 0)
			{
				this->src = src;
				this->dest = dest;
				this->weight = weight;
			}
		};
		struct compareEdge
		{
			bool operator() (const edge e1, const edge e2) const
			{	return(  e2.weight < e1.weight );				}
		};
		int V;
		vector<edge> edgeList;
		priority_queue<edge,vector<edge>, compareEdge> prior_edge;
		
		

	public:
		Graph(int V);
		void addEdge(int src, int dest, int weight);
		int findParent(int node, int parentList[]);
		bool checkLoop(struct edge e,int parentList[]);
		void unionParents(edge e, int parentList[]);
		void KruskalMST();
};

Graph::Graph(int V)
{
	this->V = V;
}

void Graph::addEdge(int src, int dest, int weight)
{
	edgeList.push_back(*(new edge(src,dest, weight)));
}

int Graph::findParent(int node, int parentList[])
{
	if(parentList[node]==-1)
		return(node);
	return( findParent(parentList[node],parentList));
}

bool Graph::checkLoop(struct edge e,int parentList[])
{
	//cout<<"Added to MST"<<endl;
	//edge e_top = e;
	
	// mstEdge -> all the edges to check for Loop
	int p1 = findParent(e.src,parentList);
	int p2 = findParent(e.dest, parentList);
	//cout<<"Source: "<<e_top.src<<"\tparent: "<<p1<<"\t Destination: "<<e_top.dest<<"\tparent: "<<p2<<"\t Weight: "<<e_top.weight<<endl;
	return((p1==p2));
}

void Graph::unionParents(edge e, int parentList[])
{
	int n1 = e.src;
	int n2 = e.dest;
	int p1 = findParent(n1, parentList);
	int p2 = findParent(n2, parentList);
	parentList[p2] = p1;
}


void Graph::KruskalMST()
{
	vector<edge> mstEdge;						// nodes added in MST
	int * parentList = new int[V];				// parents of edge -> used to check for loop in the MST

	for(int i=0;i<V;++i)		
	{
		parentList[i] = -1;
		prior_edge.push(edgeList[i]);
	}
	
	priority_queue<edge,vector<edge>, compareEdge> edge_print(prior_edge);
	cout<<"Print priority queue"<<endl;
	while(!edge_print.empty())
	{	
		//edge e = prior_edge.top();
		cout<<"Source: "<<edge_print.top().src<<"\t Destination: "<<edge_print.top().dest<<"\t Weight: "<<edge_print.top().weight<<endl;
		edge_print.pop();
	}
	cout<<endl;



	while(!prior_edge.empty())
	{
		edge e_top = prior_edge.top();
		prior_edge.pop();

		if(!checkLoop(e_top,parentList))			// if adding current Edge to MST does not cause a loop then add the edge
		{
	//		cout<<"Added to MST"<<endl;
	//		cout<<"Source: "<<e_top.src<<"\t Destination: "<<e_top.dest<<"\t Weight: "<<e_top.weight<<endl;
			mstEdge.push_back(e_top);
			unionParents(e_top,parentList);
		}
	}//prior_edge

	for(int i=0;i<mstEdge.size();++i)
		cout<<"Source: "<<mstEdge[i].src<<"\t Destination: "<<mstEdge[i].dest<<"\t Weight: "<<mstEdge[i].weight<<endl;

} //KrusalMST	


int main()
{
	// add edge 0-1
	Graph g(4);
	g.addEdge(0,1,10);
	g.addEdge(0,2,6);
	g.addEdge(0,3,5);
	g.addEdge(1,3,15);
	g.addEdge(2,3,4);

    g.KruskalMST();
 
    return 0;

};