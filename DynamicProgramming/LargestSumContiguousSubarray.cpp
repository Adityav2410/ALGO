#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int findMaxSubArraySum(int numList[],int N)
{
	int maxSum = 0;
	int start = 0,localStart=0;
	int end = 0;
	int maxSumTillHere = 0;
	for(int i=0;i<N;++i)
	{
		maxSumTillHere = maxSumTillHere+numList[i];
		if( maxSumTillHere < 0 )
		{
			localStart = i+1;
			maxSumTillHere = 0;
		}	
		if(maxSumTillHere > maxSum)
		{
			maxSum = maxSumTillHere;
			start = localStart;
			end = i;
		}
	}
	cout<<"Max Subarray sum = "<<maxSum<<endl;
	cout<<"Max Subarray bound = ("<<start<<" , "<<end<<")"<<endl;
	return maxSum;

} //maxSubArraySum


int main()
{
	int  numList[] = {-2,-3,4,-1,-2,1,5,-3};
	int maxSubArraySum = findMaxSubArraySum(numList, sizeof(numList)/sizeof(numList[0]));
	cout<<"Maximum Subarray Sum = "<<maxSubArraySum<<endl;
}
