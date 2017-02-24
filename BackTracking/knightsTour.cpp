#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

bool isValid(vector<vector<int>> board, int r, int c)
{
	return( r>= 0 && r <board.size() && c>=0 && c<board[0].size() && board[r][c]==-1);
}


bool checkKnightTour(vector<vector<int> >& board,int r,int c,int totalSteps)
{
	if(totalSteps == 64)
		return(true);	

	//vector<int> moveR = {-2,-1,+1,+2,+2,+1,-1,-2};
	//vector<int> moveC = {+1,-2,-2,-1,+1,+2,+2,+1};

	vector<int> moveR = {  2, 1, -1, -2, -2, -1,  1,  2 };
    vector<int> moveC = {  1, 2,  2,  1, -1, -2, -2, -1 };

	for(int i=0;i<8;++i)
	{
		int nro = r+moveR[i];
		int nco = c+moveC[i];
		if( isValid(board,nro,nco) )
		{	
			board[nro][nco]=totalSteps+1;
			if(checkKnightTour(board,nro,nco,totalSteps+1))
				return(true);
			board[nro][nco]=-1;		//backtracking
		}
	}
	return(false);
} //checkKnightTour


int main()
{
	int N=8;
	vector< vector<int> > board(N,vector<int>(N,-1));
	board[0][0]=1;

	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}

	int c1 = clock();
	bool ispossible = checkKnightTour(board,0,0,1);
	int c2 = clock();

	double executionTime = (c2-c1)/double(CLOCKS_PER_SEC)*1000;
	cout<<"Execution Time = "<<executionTime<<endl;

	cout<<"Traversing is POSSIBLE: "<<ispossible<<endl;

	if(ispossible)
	{
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
				cout<<board[i][j]<<"\t";
			cout<<endl;
		}
	}

} //main