#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>


using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

bool checkPalindromeString(string s, int i, int j)
{
	bool flag=true;
	while(i<j)
	{
		if(s[i]!=s[j])
		{	flag = false;	break;		}
		else
		{	++i;		--j;			}
	}
	return(flag);
}

int minPalindromePartitioning(string s,int N)
{
	int minCut[N][N] = {0};

	for(int l=2;l<=N;++l)			// for all possible length of word
		for(int i=0;i<N-l+1;++i)		// all starting index of string
		{
			int j=i+l-1;	
			for(int k=i;k<=j;++k)
				if(k==i)
					minCut[i][j]=checkPalindromeString(s,i,j)?0:INT_MAX;
				else
					minCut[i][j]=min( minCut[i][j], minCut[i][k-1]+minCut[k][j]+1);
	} // all possible length
//	for(int i=0;i<N;++i)
//	{
//		for(int j=0;j<N;++j)
//			cout<<minCut[i][j]<<"\t";
//		cout<<endl;
//	}	

	return(minCut[0][N-1]);


} //minPalindromePartitioning


int main()
{
	string str = "ababbbabbababa";
	int minCut = minPalindromePartitioning(str,str.length());
	cout<<"Minimum number of cuts required = "<<minCut<<endl;

}