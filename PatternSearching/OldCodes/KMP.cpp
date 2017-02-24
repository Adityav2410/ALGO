#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void generateLCSarray(string pattern, int lcs[])
{
	lcs[0]=0;
	int i=1;	int len=0;


	while(i<pattern.length())
	{
		if(pattern[len] == pattern[i])				
		{	
			++len;	
			lcs[i]=len;		
			++i;		
		}
		else
		{
			if(len > 0)
				len = lcs[len-1];
			else
			{
				lcs[i]=0;	
				++i;
			}
		}
	}//while loop

	for(int i=0;i<pattern.length();++i)
		cout<<pattern[i]<<"\t";
	cout<<endl;
	for(int i=0;i<pattern.length();++i)
		cout<<lcs[i]<<"\t";
	cout<<endl;

}//generateLCSarrary


void patternSearch(string text, string pattern)
{
	int lcs[pattern.length()];
	generateLCSarray(pattern,lcs);

	int i=0,j=0;

	while(i<text.length())
	{
		if(text[i]==pattern[j])
		{
			++i;
			++j;
		}

		if(j==pattern.length())
		{
			cout<<"Pattern found at "<<i-j<<endl;
			j=lcs[pattern.length()-1];
		}
		else if(i<text.length() && text[i]!=pattern[j])			//generic mismatch
		{
			if(j>0)
				j=lcs[j-1];
			else
				++i;						// when the ith character is not part of the pattern
		}
	}
}



int main()
{
	string text,pattern;
	text = "THIS TEXT IS TEST TEXT";
	pattern = "TEXT";
	//pattern = "AAAA";
	patternSearch(text,pattern);
}