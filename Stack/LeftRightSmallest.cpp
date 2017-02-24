#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<climits>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;

int * createLeftminarray(int arr[],int n,int leftMin[])
{
	stack<int> lm;
	lm.push(0);	lm.push(arr[0]);	
	leftMin[0] = 0;

	for(int i=1;i<n;++i)
	{
		while( !lm.empty() && arr[i] <= lm.top())
			lm.pop(); 
		leftMin[i] = lm.top();
		lm.push(arr[i]);
	}
	return(leftMin);
} //createLeftminarray




int * createRightminarray(int arr[],int n,int rightMin[])
{
	stack<int> lm;
	lm.push(0);			lm.push(arr[n-1]);	
	rightMin[n-1] = 0;

	for(int i=n-2;i>=0;--i)
	{
		while( !lm.empty() && arr[i] <= lm.top())
			lm.pop(); 
		rightMin[i] = lm.top();
		lm.push(arr[i]);
	}
	return(rightMin);
} //createLeftminarray





int main()
{
	int arr[] = { 2,4,8,7,7,9,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int * leftMin = new int[n];	
	int * rightMin = new int[n];
	createLeftminarray(arr,n,leftMin);
	createRightminarray(arr,n,rightMin);
	int diff[n],maximumDiff = INT_MIN;
	for(int i=0;i<n;++i)
	{
		diff[i] = abs(leftMin[i]-rightMin[i]);
		if(diff[i] > maximumDiff)
			maximumDiff = diff[i];
	}
	cout<<"Maximum Difference = "<< maximumDiff<<endl;
	delete[] leftMin;	delete[] rightMin;
}