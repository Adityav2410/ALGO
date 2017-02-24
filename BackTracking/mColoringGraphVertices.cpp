#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)


bool isSafe(vector<vector<bool>>& graph,vector<int>& color, int vertex, int c)
{
	for(int i=0;i<graph.size();++i)
	{
		if(graph[vertex][i] && color[i]==c)
			return(false);
	}
	return(true);
} //isSafe

				// graph, current vertex, previously colored vertex, total color option
bool isGraphColor(vector<vector<bool>>& graph, int vertex, vector<int>& color, int m)
{
	if(vertex>= graph.size())
		return(true);

	for(int c=0;c<m;++c)
	{
		if(isSafe(graph, color, vertex,c))
		{
			color[vertex] = c;
			if(isGraphColor(graph,vertex+1,color,m))
				return(true);
			color[vertex] = -1;
		}
	}
	return(false);
} //isGraphColor


void printColor(vector<int>& color)
{
	for(int i=0;i<color.size();++i)
		cout<<color[i]+1<<"\t";
	cout<<endl;
}

void colorGraph(vector<vector<bool>>& graph, int m)
{
	 vector<int> color(graph.size(),-1);
	 if(isGraphColor(graph,0,color, m))				// graph, current vertex, previously colored vertex, total color option
	 {	cout<<"Graph can be colored"<<endl;	printColor(color);	}
	 else
	 	cout<<"Graph can not be colored";

	 cout<<endl;
} //colorGraph


int main()
{
  	vector<vector<bool>> graph= {{0, 1, 1, 1},
    				   			{1, 0, 1, 0},
							    {1, 1, 0, 1},
							    {1, 0, 1, 0},
							   };
	int m=3;
	colorGraph(graph, m);
} //main