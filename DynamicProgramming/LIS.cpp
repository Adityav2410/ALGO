#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;

int findLIS(int * numList, int N,int maxElement)
{
	if( N == 1 )
		return numList[0]<=maxElement?1:0;
	
	if( numList[N] <= maxElement)
	{
		int l1 = findLIS(numList,N-1,numList[N]);
		int l2 = findLIS(numList,N-1,maxElement);
		return (l1+1)>l2?(l1+1):l2 ;
	}
	return findLIS(numList,N-1,maxElement) ;
}

int main()
{
	int numList[] = {10, 22, 9, 33, 21, 50,41,60,80};
	int length = findLIS(numList, sizeof(numList)/sizeof(numList[0]),INT_MAX);
	cout<<"LIS length ="<<length<<endl;

} //main 