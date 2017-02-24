#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>
#include<stack>
#include<vector>


using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void printCommonSequence( string s1,string s2, vector< vector<int> > maxCommonSeq, int l1, int l2)
{
	stack<char> letters;

	for(int i=1;i<=l1;++i)
	{
		for(int j=1;j<=l2;++j)
			cout<<maxCommonSeq[i][j]<<"\t";
		cout<<endl;
	}
	//--l1 ; --l2;

	while( maxCommonSeq[l1][l2] > 0 )
	{
		if(s1[l1-1]==s2[l2-1])
		{		
			cout<<"Common character found at "<<(l1)<<","<<(l2)<<"  =  "<<s1[l1-1]<<endl;
			letters.push(s1[l1-1]);		
				--l1;	--l2;		
		}
		else
		{
			if(maxCommonSeq[l1][l2-1] > maxCommonSeq[l1-1][l2])
			{	--l2;		}
			else
			{	--l1;		}
		}
	}

	while(!letters.empty())
	{
		cout<<letters.top()<<" ";
		letters.pop();
	}
	cout<<endl<<endl;

} //printCommonSequence

int maxCommonSuperSequence(string s1, string s2, int l1, int l2)
{
	vector<vector<int>> maxCommonSeq(l1+1,vector<int>(l2+1) );
//	memset(maxCommonSeq,0,sizeof(maxCommonSeq));

	for(int i=1;i<=l1;++i)
	{
		for(int j=1;j<=l2;++j)
		{
			if(s1[i-1]==s2[j-1])
				maxCommonSeq[i][j]=1+maxCommonSeq[i-1][j-1];
			else
				maxCommonSeq[i][j] = max( maxCommonSeq[i][j-1] , maxCommonSeq[i-1][j]);
		}
	}

	printCommonSequence(s1,s2,maxCommonSeq,l1,l2);
	return(l1+l2-maxCommonSeq[l1][l2]);



}//maxCommonSuperSequence

int main()
{
	string s1 = "AGGTAB";
	string s2 =  "GXTXAYB";
	
	int maxLength = maxCommonSuperSequence(s1,s2,s1.length(),s2.length());
	cout<<"Max SuperSequence length = "<<maxLength<<endl;

}//main