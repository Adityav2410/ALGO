#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)


bool isSafe(vector<vector<int>> board, int r, int c)
{
	int i,j;
	for(i=0;i<c;++i)
		if(board[r][i]==1)			// present in the same row
			return(false);
	for(i=r-1,j=c-1;i>=0&&j>=0;--i,--j)							// check upper diagonal
		if(board[i][j]==1)
			return(false);
	for(i=r+1,j=c-1;i<board.size() && j>=0;++i,--j)				// check lower diagonal
	{	
		if(board[i][j]==1)
			return(false);
	}


	return(true);			
}


bool findnQueenPattern(vector<vector<int>>& board, int c)
{
	if(c>=board.size())
		return(true);
	for(int r=0;r<board.size();++r)
	{
		if(isSafe(board,r,c))
		{
			board[r][c]=1;
			if(findnQueenPattern(board,c+1))
				return(true);
			board[r][c] = 0;
		}

	}
	return(false);
}


void printPositions(vector<vector<int>> board)
{
	for(int i=0;i<board.size();++i)
	{
		for(int j=0;j<board.size();++j)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}

} //printPositions

void solveNQueen(int N)
{
	vector<vector<int>> board(N,vector<int> (N,0));
	bool patternPossible = findnQueenPattern( board, 0);
	if(patternPossible)
		printPositions(board);
	else
		cout<<"No possible solutions"<<endl;
} //solveNQueen


int main()
{
	int N;
	cout<<"Enter N"<<endl;
	cin>>N;

	solveNQueen(N);

} //main
