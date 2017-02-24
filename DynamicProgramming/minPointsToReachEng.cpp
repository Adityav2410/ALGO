#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

#define R 3
#define C 3

int calculateMinStartPoint(int points[R][C])
{
	int minPoints[R][C];
	minPoints[R-1][C-1] = max(1-points[R-1][C-1],1);
	for(int i=C-2;i>=0;--i)
		minPoints[R-1][i] = max( minPoints[R-1][i+1]-points[R-1][i],1);
	for(int i=R-2;i>=0;--i)
		minPoints[i][C-1] = max( minPoints[i+1][C-1]-points[i][C-1],1);

	for(int i=R-2;i>=0;--i)
		for(int j=C-2;j>=0;--j)
			minPoints[i][j] = max( min(minPoints[i+1][j],minPoints[i][j+1])-points[i][j],1);

	for(int i=0;i<R;++i)
	{	
		for(int j=0;j<C;++j)
			cout<<minPoints[i][j]<<"\t";
		cout<<endl;		
	}	

	cout<<"MinStart Points Required = "<<minPoints[0][0]<<endl;
}


int main()
{
	int points[R][C] = {  {-2,-3,3},
                	      {-5,-10,1},
                    	  {10,30,-5}
                    	};

    int minStartPoint = calculateMinStartPoint(points);
    cout<<"Minimum Start points needed to complete the journey = "<<minStartPoint<<endl;                	
}