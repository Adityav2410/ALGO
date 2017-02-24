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

void findMinDistVertex(vector<int> dist, vector<bool> mstSET, int & src, int & dest, vector<vector<int>> Graph)
{
	int d = INT_MAX;
	
	for(int i=0;i<dist.size();++i)
	{
		if( !mstSET[i] && dist[i] < d )
		{
			d = dist[i];
			dest = i;
		}
	}
	for(int i=0;i<dist.size();++i)
	{
		if(mstSET[i] && Graph[i][dest] == d)
		{	src = i;	break;		}
	}
} // findMinDistVertex


void updateDist(vector<int> & dist, vector<vector<int> > Graph, int src)
{
	for(int i=0; i< dist.size(); ++i)
		dist[i] = Graph[src][i]!=0?min(dist[i],Graph[src][i]):dist[i]; 
}

void primMST(vector<vector<int>> Graph)
{
	int N = Graph.size();
	vector<bool> mstSET (N,false) ;
	vector<int> dist(N,INT_MAX) ;
	int remainVertex = N-1;
	dist[0] = 0;
	int src=0,dest=0;

	mstSET[0] = true;
	updateDist(dist, Graph, 0);

	for(int i=0;i<N; ++i)
		cout<<dist[i]<<"\t";
	cout<<endl;

	while( remainVertex > 0)
	{
		findMinDistVertex(dist,mstSET, src, dest,Graph);
		mstSET[dest] = true;
		updateDist(dist, Graph, dest);
		cout<<"Edge "<<src<<" --- "<<dest<<"    :    "<<Graph[src][dest]<<endl;
		--remainVertex;
	}
}//primMST


int main()
{
	vector<vector<int>> Graph	 = 	 {{0, 2, 0, 6, 0},
				                      {2, 0, 3, 8, 5},
				                      {0, 3, 0, 0, 7},
				                      {6, 8, 0, 0, 9},
				                      {0, 5, 7, 9, 0},
				                     };


	primMST(Graph);				                   
}//main