#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void createZarray(string text,int zArray[])
{
	int L=0,R=0;
	int l=text.length();

	for(int i=1;i<l;++i)
	{
		if(R<i)			// when the current index is out of boundary of R
		{
			L=R=i;
			while(R<l && text[R]==text[R-L])
				++R;
			zArray[i] = R-L;
			--R;
		}
		else
		{
			if(zArray[i-L] < R-i+1)
				zArray[i] = zArray[i-L];
			else
			{
				L=i;
				while(R<l && text[R]==text[R-L])
					++R;
				zArray[i] = R-L;
				--R;
			}
		}
	}
	cout<<endl;
	for(int i=0;i<l;++i)
		cout<<text[i]<<" ";
	cout<<endl<<"  ";
	for(int i=1;i<l;++i)
		cout<<zArray[i]<<" ";
	cout<<endl;
}

void zSearch(string text, string pattern)
{
	string s = pattern+"$"+text;
	int l = s.length();
	int M = pattern.length();
	int zArray[l];
	
	createZarray(s,zArray);

	for(int i=M;i<l;++i)
		if(zArray[i]==M)
			cout<<"Pattern found at "<<i-M-1<<endl;



}//zSearch

int main()
{
	string text, pattern;
	text = "THIS TEXT IS TEST TEXT";
	pattern = "TEXT";

	zSearch(text,pattern);
}//main