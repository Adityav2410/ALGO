#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;

int calculateKnapsackMaxValue(int value[],int weight[],int l,int limit)
{
	if(limit < weight[l])
		return 0;
	if(l==0)
		return value[l];
	int val1 = calculateKnapsackMaxValue(value,weight,l-1,limit);	// last element absent in knapsack
	int val2 = calculateKnapsackMaxValue(value,weight,l-1,limit-weight[l]);
	return max(val1,val2+value[l]) ;
} // calculateKnapsackMaxValue

int main()
{
	int value[]  = {60,100,120} ;
	int weight[] = {10,20,30} ;
	int limit = 50;
	int l = sizeof(weight)/sizeof(weight[0]);
	int maxValue = calculateKnapsackMaxValue(value,weight,l-1,limit);
	cout<<"Maximum Value = "<<maxValue<<endl;

} //main