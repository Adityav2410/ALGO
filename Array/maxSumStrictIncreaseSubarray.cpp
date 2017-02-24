#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;

int maxSubarraySum(int arr[],int l,int r,int lowerLimit)
{
	if(l==r)
		return arr[r]>lowerLimit?arr[r]:0;

	int sum1 = INT_MIN;
	if(arr[l]>lowerLimit)
		sum1 = arr[l]+maxSubarraySum(arr,l+1,r,arr[l]);
	int sum2 = maxSubarraySum(arr,l+1,r,lowerLimit);
	return max(sum1,sum2);

}

int main()
{
	int arr[] = {1,2,3,2,5,1,7};

	int maxSum = maxSubarraySum(arr,0,(sizeof(arr)/sizeof(arr[0]))-1,INT_MIN);
	cout<<"Maximum Subarray Sum = "<<maxSum<<endl;


} //main