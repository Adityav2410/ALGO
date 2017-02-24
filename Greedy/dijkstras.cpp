#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<list>
#include<vector>


using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int findMin(vector<bool> mstSet, vector<int> dist)
{
	int N = mstSet.size();
	int minIndex = 0;
	int minDist = INT_MAX;
	for(int i=0; i<N; ++i)
	{
		if(!mstSet[i] && dist[i] < minDist)
		{
			minDist = dist[i];
			minIndex = i;
		}
	}

	return(minIndex);
}

void dijkstra(vector<vector<int>> graph, int start)
{
	int N = graph.size();
	vector<bool> mstSet (N,false);
	vector<int> dist (N, INT_MAX);

	dist[start] = 0;

	for(int i=0; i<N; ++i)
	{
		int u = findMin(mstSet, dist);
		
		//cout<<"i = "<<i<<"\t MinIndex = "<<u<<endl;
		//for(int j=0; j<N; ++j)
		//cout<<"Node: "<<j<<"\t distance: "<<dist[j]<<endl;
		mstSet[u] = true;

		for(int j=0; j< N; ++j)
		{
			if( !mstSet[j] && graph[u][j] && dist[u] + graph[u][j] <  dist[j])
				dist[j] = dist[u] + graph[u][j] ;
		}

	}

	for(int i=0; i<N; ++i)
		cout<<"Node: "<<i<<"\t distance: "<<dist[i]<<endl;

}


int main()
{

	vector<vector<int>> graph = 	 {{0, 4, 0, 0, 0, 0, 0, 8, 0},
				                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
				                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
				                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
				                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
				                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
				                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
				                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
				                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
				                     };
	  
	dijkstra(graph, 0);
	return 0;

} //main