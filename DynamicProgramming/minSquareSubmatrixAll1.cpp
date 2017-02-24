#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

#define R 6
#define C 5


void maxSquareSubmatrix(bool M[R][C])
{
	int square[R+1][C+1]={0};
	for(int i=1;i<=R;++i)
		for(int j=1;j<=C;++j)
		 	if(M[i-1][j-1]==1)
				square[i][j] = min( min(square[i-1][j-1],square[i][j-1]), square[i-1][j] )+1;

	for(int i=1;i<=R;++i)
	{
		for(int j=1;j<=C;++j)
			cout<<square[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl<<endl;
	
	int maxSquareSize=INT_MIN;
	for(int i=1;i<=R;++i)
		for(int j=1;j<=C;++j)
			maxSquareSize = max( maxSquareSize, square[i][j]);	
	cout<<"Maximum Square Submatrix side = "<<maxSquareSize<<endl;	

}


int main()
{
	  bool M[R][C] =    {  {0, 1, 1, 0, 1}, 
                   		   {1, 1, 0, 1, 0}, 
	                	   {0, 1, 1, 1, 0},
	                	   {1, 1, 1, 1, 0},
	                	   {1, 1, 1, 1, 1},
	                	   {0, 0, 0, 0, 0}
	                	};

	 maxSquareSubmatrix(M);
} //main