#include<iostream>
#include<cstdlib>
#include<climits>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;

int main()
{
	int mSize[] = {40,20,30,10,30};
	int N=sizeof(mSize)/sizeof(mSize[0])-1;
	int multiplyCost[N+1][N+1];
	for(int i=0;i<=N;++i)
		multiplyCost[i][i]=0;

	for(int i=0;i<=N;++i)
	{
		for(int j=0;j<=N;++j)
			multiplyCost[i][j]=0;
	}


	for(int l=2;l<=N;++l)					//for all the possible length
	{
		for(int i=1;i+l-1<=N;++i)				// for a given length, all the possible starting position
		{
			int j=i+l-1;
			multiplyCost[i][j] = INT_MAX ;
			for(int k=i;k<j;++k)
			{
				int cost = multiplyCost[i][k] + multiplyCost[k+1][j] + mSize[i-1]*mSize[k]*mSize[j];
				if(i == 1 && j==3 && k==2)
				{	
					cout<<"Cost component = "<<multiplyCost[i][k]<<"\t"<<multiplyCost[k+1][j]<<"\t"<<mSize[i-1]*mSize[k]*mSize[j]<<endl;
					cout<<"Cost "<<k<<" = "<<cost<<endl;
				
				}
				if(cost < multiplyCost[i][j])
					multiplyCost[i][j]=cost; 
			}
		}
	}
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
			cout<<multiplyCost[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"Minimum Multiplication cost= "<<multiplyCost[1][N]<<endl;
}