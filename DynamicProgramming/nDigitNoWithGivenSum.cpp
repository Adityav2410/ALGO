#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdlib>
#include<string>


using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int numberofNumbersWithGivenSum(int N,int sum)
{
	int combo[sum+1][N+1];
	for(int i=0;i<=N;++i)
		combo[0][i]=1;
	for(int i=1;i<=9;++i)
		combo[i][1]=1;
	for(int i=10;i<=sum;++i)
		combo[i][1]=0;

	for(int i=1;i<=sum;++i)
		for(int j=2;j<=N;++j)
		{
			combo[i][j]=0;
			for(int k=0;k<=9;++k)
			{
				if(i-k>=0)
					combo[i][j] += combo[i-k][j-1];
			}
		}

	for(int i=1;i<=sum;++i)
	{	for(int j=1;j<=N;++j)
			cout<<combo[i][j]<<"\t";
		cout<<endl;
	}


	return( combo[sum][N]-combo[sum][N-1]);	

}//numberofNumbersWithGivenSum


int main()
{
	int N,sum;
	cout<<"Enter N-the number of digits and SUM-the expected sum of digits"<<endl;
	cin>>N>>sum;
	int count = numberofNumbersWithGivenSum(N,sum);
	cout<<"Possible Combinations ="<<count<<endl;
}