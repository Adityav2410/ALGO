#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

#define V 5


void printPath(vector<int>& path)
{
	for(int i=0;i<path.size();++i)
		cout<<path[i]<<"\t";
	cout<<endl;
}


bool checkHamiltonianPath(bool graph[V][V], vector<int>& path,int vertex)
{
	//cout<<"Step count = "<<path[vertex]<<" at vertex:"<<vertex<<endl;
	if( path[vertex]==V && graph[vertex][0])
		return(true);
	
	for(int i=0;i<V;++i)		// check for every vertex next to the current vertex
	{
		if(graph[vertex][i] && !path[i])		// 'i' node has not been traversed till yet
		{
			path[i] = path[vertex]+1;
			if(checkHamiltonianPath(graph,path,i))
				return(true);
			path[i]=0;
		}
	}
	return false;
}//checkHamiltonianPath	



void hamiltonianPath(bool graph[][V])
{
	vector<int> path(V,0);
	path[0]=1;
	if(checkHamiltonianPath(graph,path,0))
	{	cout<<"Hamiltonian Path Exist"<<endl;	printPath(path);	}
	else
		cout<<"No Hamiltonian Path in the given Graph"<<endl;


}//hamiltonianPath


int main()
{
	bool graph1[V][V] = {  {0, 1, 0, 1, 0},
                 		  	  {1, 0, 1, 1, 1},
		                      {0, 1, 0, 0, 1},
		                      {1, 1, 0, 0, 1},
		                      {0, 1, 1, 1, 0},
		                    };	

	hamiltonianPath(graph1);		 

	bool graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };                  

	hamiltonianPath(graph2);                     

} //main