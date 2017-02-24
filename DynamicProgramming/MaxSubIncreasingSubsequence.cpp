#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>


using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)


int main()
{
	int list[] = {0,1,101,2,3,100,4,5};
	int l = sizeof(list)/sizeof(list[0]);
	int maxSum[l] = {0};
	
	for(int i=1;i<l;++i)
		for(int j=0;j<i;++j)
			maxSum[i] = list[j]<list[i]?max( maxSum[i],maxSum[j]+list[i]) : maxSum[i];
		

	int maxIncSum=INT_MIN;	
	for(int i=1;i<l;++i)	
	{	cout<<maxSum[i]<<"\t";		maxIncSum = max(maxIncSum,maxSum[i]);			}
	cout<<endl;

	cout<<"MIS in the list = "<<maxIncSum<<endl;

} //main