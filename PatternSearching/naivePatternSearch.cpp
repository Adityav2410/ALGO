#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void patternSearch(string text,string pattern)
{
	for(int i=0;i<=text.length()-pattern.length();++i)
	{
		int j=0;
		while(j<pattern.length() && text[i+j]==pattern[j])
		{
			if(j==pattern.length()-1)
				cout<<"Pattern found at "<<i<<endl;
			++j;
		}

	}

}//patternSearch

int main()
{
	string text,pattern;
	text = "THIS TEXT IS TEST TEXT";
	pattern = "TEXT";
	patternSearch(text,pattern);
}