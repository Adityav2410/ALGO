#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void printSubset(int arr[],int subset[],int N,int totSum,int minDiff)
{
	int subsetSum=0,subsetCount=0;
	for(int i=0;i<N;++i)
	{	subsetSum+=subset[i]*arr[i];
		subsetCount+=subset[i];
	}	
	cout<<"\nThe minimum difference between two sets: "<<minDiff<<endl;
	
	cout<<"Terms in 1st subset = "<<(subsetCount)<<endl;	
	for(int i=0;i<N;++i)
		if(subset[i])
			cout<<arr[i]<<"\t";
	cout<<endl;	
	cout<<"Sum of terms in Subset1: "<<subsetSum<<endl<<endl;;
	cout<<"Terms in 2nd subset = "<<(N-subsetCount)<<endl;
	for(int i=0;i<N;++i)
		if(!subset[i])
			cout<<arr[i]<<"\t";
	cout<<endl;	
	cout<<"Sum of terms in Subset1: "<<subsetSum<<endl;
}

void generateminDiffSubsetList(int arr[],int N,int subset[],int count,int index,int subsetSum,int totSum,int minsumSubset[],int & minDiff)
{
	//cout<<"Till yet elements in subset="<<count<<" Checking value at index "<<index<<endl;
	
	if(count==N/2)
	{
	 	if(abs(totSum-2*subsetSum) < minDiff)
		{	
			for(int i=0;i<N;++i)		
				minsumSubset[i]=subset[i];
			minDiff = abs(totSum-2*subsetSum);
		}
		return;
	}

	if(N-index < N/2-count)
		return;
	
	
	//include the current- 'index' term in the list
	subset[index]=1;
	generateminDiffSubsetList(arr,N,subset,count+1,index+1,subsetSum+arr[index],totSum,minsumSubset,minDiff);

	subset[index]=0;
	generateminDiffSubsetList(arr,N,subset,count,index+1,subsetSum,totSum,minsumSubset,minDiff);
}

void tugOfWar(int arr[],int N)
{
	int subset[N]={0};			
	int count=0;	
	int index=0;
	int subsetSum=0;
	int minDiff = INT_MAX;
	int minsumSubset[N]; 	memset(minsumSubset,0,N);

	int totSum=0;
	for(int i=0;i<N;++i)
		totSum+=arr[i];
	
	generateminDiffSubsetList(arr,N,subset,count,index,subsetSum,totSum,minsumSubset,minDiff);
	printSubset(arr,minsumSubset,N,totSum,minDiff);
}//tugOfWar


int main()
{
	//int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int arr[]={3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
	int N= sizeof(arr)/sizeof(arr[0]);
	tugOfWar(arr,N);

} //main