#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

#define N 9

void printSolution(int grid[N][N])
{

	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			cout<<grid[i][j]<<"";
			if(j%3==2)
				cout<<"\t";
		}
		if(i%3==2)
			cout<<endl<<endl;	
		cout<<endl;
	}

}


bool isSafe(int grid[N][N],int r, int c, int val)
{
	for(int i=0;i<9;++i)
	{
		if( (i!=c && grid[r][i]==val) || ( i!=r && grid[i][c]==val) )		// check in row and column
			return(false);
		
		int r_grid = (r/3)*3;	int c_grid = (c/3)*3;
		for(int i=r_grid; i<=r_grid+2;++i)
		{
			for(int j=c_grid;j<=c_grid+2;++j)
				if( !(i==r && j==c) && grid[i][j]==val)
					return(false);
		}
	}
	return true;
}//isSafe

bool findRecurrsiveSolution(int grid[N][N], int r, int c)
{
	//cout<<"Checking solution for index "<<r<<","<<c<<endl;
	while(r>=0 && r<N && c>=0 && c<N && grid[r][c])
	{
		int nco=(c+1)%9; 
		r=r+(c+1)/9;
		c=nco;
	}
	//cout<<"Some already occupied index. lasted till "<<r<<","<<c<<endl;

	if(r==N)
		return(true);

	for(int i=1;i<=9;++i)		// check for every possible number for the current location
	{
		if(isSafe(grid,r,c,i))
		{
			grid[r][c]=i;

			int nco=(c+1)%9;
			int nro=r+(c+1)/9;

			if(findRecurrsiveSolution(grid, nro,nco))
				return(true);
			grid[r][c]=0;
		}
	}
	return(false);
}//findRecurrsiveSolution

void solveSoduku(int grid[N][N])
{
	if(findRecurrsiveSolution(grid,0,0))
	{	cout<<"Soduku Solved"<<endl;	printSolution(grid);	}
	else
	cout<<"No solution exist to the given SODUKU"<<endl;
}//solveSoduku

int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	solveSoduku(grid);                      
}//main