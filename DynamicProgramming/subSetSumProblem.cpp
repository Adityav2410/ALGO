#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)


bool checkSubSetSum(int set[],int sum, int N)
{
	bool subSetSum[N+1][sum+1]={true};
	for(int i=0;i<=sum;++i)
		subSetSum[0][i]=false;
	for(int i=0;i<=N;++i)
		subSetSum[i][0]=true;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=sum;++j)
		{
			bool option1 = set[i-1]<=j?subSetSum[i-1][j-set[i-1]]:false;				//when the number is included
			bool option2 = subSetSum[i-1][j];
			subSetSum[i][j] = option1 || option2 ;
		}
	return(subSetSum[N][sum]);	
}


int main()
{
	int set[] = {3,34,4,12,4,1};
	int sum =9;
	bool subsetSum = checkSubSetSum(set,sum,sizeof(set)/sizeof(set[0]));
	if(subsetSum)
		cout<<"The Set has a subset with given Sum"<<endl;
	else
		cout<<"No Subset with given sum possible"<<endl;

}