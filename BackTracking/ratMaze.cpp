#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

bool isValid(vector<vector<int>>& maze, int r, int c)
{
	return( r>=0 && r< maze.size() && c>=0 && c<maze.size() && maze[r][c]==1);
}

bool mazePath(vector<vector<int>>& maze,vector<vector<int>>& path,int r, int c)
{
	if(r==maze.size()-1 && c==maze.size()-1)
	{	path[r][c]=1;	return(true);		}

	path[r][c]=1;		//assume that the current location is a part of the optimized path
	if( isValid(maze,r+1,c) && mazePath(maze,path,r+1,c) )				// if going down is valid
		return(true);

	if( isValid(maze,r,c+1) && mazePath(maze,path,r,c+1) )
		return(true);
	path[r][c]=0;
	return(false);
}//mazePath


int main()
{

    vector<vector<int>> maze =  { {1, 0, 0, 0},
      					  		  {1, 1, 0, 1},
								  {0, 1, 0, 0},
								  {1, 1, 1, 1}
								};

	cout<<"size of maze = "<<maze.size()<<" , "<<maze[0].size()<<endl;
	int N = maze.size();
	vector<vector<int>> path(maze.size(), vector<int>(maze.size(),0));
	mazePath(maze,path,0,0);


	cout<<"-----MAZE-------"<<endl;
	for(int i=0;i<path.size();++i)
	{
		for(int j=0;j<path.size();++j)
			cout<<maze[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"\n\n\n\n\n--------PATH---------"<<endl;
	for(int i=0;i<path.size();++i)
	{
		for(int j=0;j<path.size();++j)
			cout<<path[i][j]<<"\t";
		cout<<endl;
	}

} //main