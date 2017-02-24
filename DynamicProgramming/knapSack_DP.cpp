#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;

int main()
{
	int value[] = {60,100,120};
	int weight[]= {10,20,30};
	int limit = 50;
	int l = sizeof(weight)/sizeof(weight[0]);
	int valueList[limit+1][l+1];

	for(int i=0;i<=l;++i)
		valueList[0][i] = 0;
	for(int i=0;i<=limit;++i)
		valueList[i][0]=0;


	for(int i=1;i<=limit;++i)
	{
		for(int j=1;j<=l;++j)
		{
			int val1=0, val2=0;
			if(i-weight[j-1] >=0)		//jth element present in knapsack
				val1 = valueList[i-weight[j-1]][j-1] + value[j-1];
			val2 = valueList[i][j-1];
			valueList[i][j]=max(val1,val2);
		}
	}
	cout<<"Max Value of Knapsack = "<< valueList[limit][l]<<endl;
}