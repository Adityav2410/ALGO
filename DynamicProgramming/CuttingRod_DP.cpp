#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int main()
{
	int cost[] = {0,3,5,8,9,10,17,17,20};
	int maxRodSize = sizeof(cost)/sizeof(cost[0]);
	int rodLength;
	cout<<"Enter rod Length"<<endl;
	cin>>rodLength;
	int maxRodCost[rodLength+1]={0};

	for(int i=1;i<=rodLength;++i)
		for(int j=i;j>=1;--j)
			if(j==i && i<=maxRodSize)
				maxRodCost[i] = cost[j];
			else
				maxRodCost[i] = max(maxRodCost[j]+maxRodCost[i-j], maxRodCost[i]);


	for(int i=1;i<=rodLength;++i)
		cout<<maxRodCost[i]<<"\t";
	cout<<endl;

	cout<<"Max Rod cutting cost = "<<maxRodCost[rodLength]<<endl;	


}//main