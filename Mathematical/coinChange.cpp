#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void printCombinationsVector(vector<int> combinations)
{
	for(int i=0; i< combinations.size(); ++i)
		cout<<combinations[i]<<"\t";
	cout<<endl;
}

void printCombinationsUtil(int N, vector<int> combinations,vector<int> coins, int nc)
{
	//cout<<"N="<<N<<endl;
	if(N==0)
	{
		printCombinationsVector(combinations);	
		return;
	}
	for(int i=0; i<nc; ++i)
		if(N >= coins[i])
		{
			combinations.push_back(coins[i]);
			printCombinationsUtil(N-coins[i],combinations, coins, nc);
			combinations.pop_back();
		}	
}

void printCombinations(int N, vector<int> coins, int nc)
{
	vector<int> combinations(0,0);
	printCombinationsUtil(N, combinations,coins, nc);
} 

int main()
{
	int N;
	cout<<"Enter amount"<<endl;
	cin>>N;
	vector<int> coins = {1,2,5};
	int nc = coins.size();
	printCombinations(N,coins,nc);
}