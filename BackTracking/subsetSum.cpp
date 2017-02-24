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

void printNumbers(int weight[], int present[], int N)
{
	for(int i=0;i<N;++i)
		if(present[i])
			cout<<weight[i]<<"\t";
	cout<<endl;	
}


void isSubsetPossible(int target, int weight[], int present[],int N, int totalSum,int index,int&count)
{
	// the search ends at current index
	if(index>=N)
		return;
	if(weight[index]==target)		
	{
		present[index]=1;
		printNumbers(weight,present,N);
		present[index]=0;
		++count;
		return ;
	}

	// check if index-element <= target. if curr Element > target,no combo possible
	if(weight[index]>target)
		return;

	//if current element is present in the Subset
	if(totalSum-weight[index]>=target-weight[index])
	{
		present[index] = 1;
		isSubsetPossible(target-weight[index],weight,present,N,totalSum-weight[index],index+1,count);
		present[index] = 0;
	}
	if(totalSum-weight[index] >= target)	
	{
		present[index]=0;
		isSubsetPossible(target,weight,present,N,totalSum-weight[index],index+1,count);	
	}	
}

void generateSubset(int target, int weight[], int N)
{
	int present[N];	memset(present, 0,sizeof(present));

	sort(weight,weight+N)	;
	int totalSum=0;
	for(int i=0;i<N;++i)
		totalSum += weight[i];
	int count = 0;
	isSubsetPossible(target, weight,present,N,totalSum,0,count);
	if(count)
		cout<<"Total Number of possible subset ="<<count<<endl;
	else
		cout<<"No subset possible with sum as given target"<<endl;

}//generateSubSet

int main()
{
	int weight[] = {15,22,14,26,32,9,16,8};
	int target = 53;
	generateSubset(target, weight, sizeof(weight)/sizeof(weight[0]));
} //main
