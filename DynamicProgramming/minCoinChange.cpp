#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int minCoinChangeCombo(int V, int coin[],int m)
{
	int change[V+1] = {0};
	for(int i=1;i<=V;++i)
	{
		change[i] = INT_MAX;
		for(int k=0;k<m;++k)
		{
			if( i >= coin[k] && change[i-coin[k]]!=INT_MAX)
				change[i] = min( change[i], 1+change[i-coin[k]]);
		}
	}

	for(int i=0;i<=V;++i)
		cout<<change[i]<<"\t";
	cout<<endl<<endl;
	return(change[V]);
} //minCoinChangeCombo


int main()
{
	int coin[] = {25,10,5};
	int m = sizeof(coin)/sizeof(coin[0]);
	int V;
	cout<<"Enter Value"<<endl;
	cin>>V;
	int minCombo = minCoinChangeCombo(V,coin,m);
	cout<<"Minimum number of coins required for the Value = "<<minCombo<<endl;
}