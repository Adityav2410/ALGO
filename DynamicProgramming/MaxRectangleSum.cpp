#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

#define R 4
#define C 5


int kadane(int arr[],int N, int &top, int &bottom,int p1, int p2)
{
	int sum = 0,maxSum= INT_MIN;
	int localStart = -1;
	for(int i=0;i<N;++i)
	{
		sum = sum+arr[i];
		
		if(sum < 0)
		{
			sum = 0;
			localStart = i+1;
		}

		if(sum > maxSum)
		{
			maxSum= sum;
			bottom = i;
			top = localStart;
		}
	}
	return(maxSum);

}//kadane

void findMaxRectangeSum(int M[R][C])
{
	int topRow=0,bottomRow=0,leftColumn=0,rightColumn=0;
	int maxSum=INT_MIN;
	for(int i=0;i<C;++i)
	{
		int rowSum[R]={0};
		for(int j=i;j<C;++j)
		{
			int colSum[R]={0};
			int localRowTop=0,localRowBottom=0;
			
			for(int k=0;k<R;++k)
				rowSum[k]+=M[k][j];

			int currentColumnSum=kadane(rowSum,R,localRowTop,localRowBottom,i,j);
			if(currentColumnSum>maxSum)
			{
				maxSum = currentColumnSum;
				leftColumn = i;			rightColumn = j;
				topRow = localRowTop;	bottomRow = localRowBottom;
			}
		}
	}

	cout<<"Max Rectangle Sum = "<<maxSum<<endl;
	cout<<"Rectangle Coordinates: ("<<topRow<<","<<leftColumn<<" ) - ("<<bottomRow<<","<<rightColumn<<")"<<endl<<endl;
} //findMaxRectangleSum



int main()
{
	int M[R][C] = 	{	{1,		2,	-1,	-4,	-20	},
						{-8,	-3,	4,	2,	1	},
						{3,		8,	10,	1,	3	},
						{-4,	-1,	1,	7,	-6	}	
					};

	findMaxRectangeSum(M);				




} //main