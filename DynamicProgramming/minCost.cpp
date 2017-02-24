#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define max(x,y) ( x>y?x:y)
#define min(x,y) ( x<y?x:y)
#define COL 5

using namespace std;


int main()
{
	int path[3][3] = { 	{1,2,3},
						{4,8,2},
						{1,5,3}
					} ;
	int cost[2][2];
	for(int i=0;i<=2;++i)
		for(int j=0;j<=2;++j)
		{
			if(i==0)
				cost[i][j]=cost[i][j-path(i,j);
			else
				cost[i][j] =  + min( min( cost[i-1][j],cost[i][j-1] ) , cost[i-1][j-1]);
		}
		for(int i=0;i<=2;++i)
		{
			for(int j=0;j<=2;++j)
				cout<<cost[i][j]<<"\t";
			cout<<endl;
		}


	cout<<"Min Cost path = "<<cost[2][2]<<endl;


} //main

