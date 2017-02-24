#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define max(a,b) ( a>b?a:b)
using namespace std;


int generateCostMatrix(string s1, string s2)
{
	int cost[s1.length()+1][s2.length()+1],i,j;
	for(i=0;i<=s1.length();++i)
		for( j=0;j<=s2.length();++j)
		{
			if(i==0 || j==0)
				cost[i][j] = 0;
			else if(s1.at(i-1) == s2.at(j-1))
				cost[i][j] = cost[i-1][j-1]+1;
			else
				cost[i][j] = max(cost[i][j-1],cost[i-1][j]);
		}

	return(cost[i-1][j-1]);

}

int main()
{
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	int cost = generateCostMatrix(s1,s2);
	cout<<"The length of LCS = "<<cost<<endl;


}