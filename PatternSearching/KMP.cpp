#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void generateLCSarray(string pattern,int lcs[],int M)
{
	lcs[0]=0;
	int i=1,len=0;
	while(i<M)
	{
		if(pattern[i]==pattern[len])
		{
			++len;
			lcs[i]=len;
			++i;
		}
		else
		{
			if(len>0)
				len = lcs[len-1];
			else
			{
				lcs[i]=0;
				++i;
			}
		}
	}

	for(int i=0;i<M;++i)
		cout<<pattern[i]<<"\t";
	cout<<endl;
	for(int i=0;i<M;++i)
		cout<<lcs[i]<<"\t";
	cout<<endl;
}//generateLCSarray



void KMPsearch(string text,string pattern, int N, int M)
{
	int lcs[M];
	generateLCSarray(pattern,lcs,M);
	int i=0,j=0;

	while(i<N)
	{
		if(text[i]==pattern[j])
		{
			++i;	++j;
		}
		if(j==M)
		{
			cout<<"Pattern found at "<<i-j<<endl;
			j=lcs[j-1];
		}
		else if( i<N && text[i]!=pattern[j])
		{
			
			j=j>0?lcs[j-1]:0;
			if(j>0)
				j=lcs[j-1];
			else
			{	++i;	j=0;	}

		}

		
	}//while every character traversal
}

int main()
{
	string text,pattern;
	text = "THIS TEXT IS TEST TEXT";
	pattern = "TEXT";

	KMPsearch(text,pattern,text.length(),pattern.length());


}//main