#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>
#include<stack>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int calculateMinSteptoEnd(int step[],int endSpot)
{
	int maxDistance = 0;
	int minStep[endSpot] = {0};
	for(int i=0;i<endSpot;++i)
		minStep[i] = INT_MAX;
	minStep[0] = 0;
	int previousStep[endSpot]={0};
	for(int i=0;i<endSpot;++i)
	{
		if(i>maxDistance)
		{	cout<<"FAIL: Cannot reach till the end"<<endl;	return -1;	}
		maxDistance = max(maxDistance,i+step[i]);
		for(int j=i+1; j<min(i+step[i]+1,endSpot);++j)
			if( minStep[i]+1 < minStep[j] )
			{	minStep[j] = minStep[i]+1;		previousStep[j]=i;		}
	}

	int i=endSpot-1;
	stack<int> st;
	while(i!=0)
	{
		st.push(step[i]);
		i = previousStep[i];
	}
	st.push(step[0]);
	while(!st.empty())
	{	cout<<st.top()<<" --> ";
		st.pop();
	}	

	cout<<endl;
	
	return(minStep[endSpot-1]);
}

int main()
{
	int step[] = {1,3,5,8,9,2,6,7,6,8,9};
	int minStep = calculateMinSteptoEnd(step,sizeof(step)/sizeof(step[0]));
	cout<<"Minimum number of steps to end =  "<<minStep<<endl;
} //main