#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void RabinKarpSearch(string text, string pattern,int q)
{
	int D=256;
	int pK = 0;
	int tK=0;
	int h=1;
	int j;
	for(int i=0;i<pattern.length()-1;++i)
		h=(h*D)%q;

	for(int i=0;i<pattern.length();++i)
	{	
		pK = (D*pK+pattern[i])%q;
		tK = (D*tK+text[i])%q;
	}
	cout<<"Pattern Key = "<<pK<<endl<<endl;
	
	for(int i=0;i<=text.length()-pattern.length();++i)
	{
		cout<<tK<<"\t";
		if(tK == pK && pattern[0]==text[i])
		{
			for(j=1;j<pattern.length();++j)
				if(pattern[j]!=text[i+j])
					break;

			if(j==pattern.length())
				cout<<"Pattern found at "<<i<<endl;	
		}
		if(i<text.length()-pattern.length())
			tK = ( D*(tK-h*text[i]) + text[i+pattern.length()])%q;
		if(tK<0)
			tK = tK+q;
	}
}


int main()
{
	string text, pattern;
	text = "THIS TEXT IS TEST TEXT";
	pattern = "TEXT";
	//text = "GEEKS FOR GEEKS";
	//pattern = "GEEK";
	int q=101;
	RabinKarpSearch(text,pattern,q);
} //main
