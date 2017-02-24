#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define min(x,y) (x<y?x:y)

using namespace std;

int main()
{
	int n,k;
	cout<<"Enter n and k"<<endl;
	cin>>n>>k;

	if(k>n || n==0)
	{
		cout<<"Invalid input"<<endl;
		return 0;
	}	

	int ncr[n+1][k+1];


	for(int i=0;i<=n;++i)
		for(int j=0;j<=k;++j)
		{
			if(j==0)
				ncr[i][j]= 1;
			else	
				ncr[i][j]=0;
		}
	

	for(int i=1;i<=n;++i)
		for(int j=1;j<=min(i,k);++j)
			ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
	
	cout<<"nCk = "<<ncr[n][k]<<endl;



}