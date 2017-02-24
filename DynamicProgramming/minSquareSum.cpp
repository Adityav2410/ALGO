#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int minSquareSum(int N)
{
	int count[N+1]={0};	count[1] = 1;
	int x;

	for(int i=2;i<=N;++i)
		for(x=1,count[i]=INT_MAX;x*x<=i;++x)
			count[i] = min(count[i], 1+count[i-x*x]);
	
	return(count[N]);
} //minSquareSum


int main()
{
	int N;
	cout<<"Enter number"<<endl;
	cin>>N;

	int count = minSquareSum(N);
	cout<<"Minimum number of square terms = "<<count<<endl;
}