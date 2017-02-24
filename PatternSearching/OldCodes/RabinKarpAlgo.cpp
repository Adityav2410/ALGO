#include<iostream>
#include<cstdlib>
#include<cstring>

#define d 256
using namespace std;

void matchPattern(string text,string pattern, int N, int M,int q)
{
	int h=1,p=0,t=0;
	for(int i=0;i<M;++i)
	{
		p = (p*d + pattern[i])%q;
		t = (t*d + text[i])%q;
	}
	for(int i=1;i<M;++i)
		h = (h*d)%q;

	cout<<"D = "<<d<<endl;
	cout<<"Pattern Hash Value = "<<p<<endl;
	cout<<"Text First Block Hash Value = "<<t<<endl;
	cout<<"H = "<<h<<endl;

	for(int i=0, j=0 ;i<= N-M;++i)
	{
		if( t == p )
		{
			for(j=0;j<M;++j)
				if(text[i+j]!=pattern[j])
					break;
			if(j==M)
				cout<<"Pattern found at "<<i<<endl;
		}

		t = ( d*( t - h*text[i] ) + text[i+M]) %q;
		t = t<0?(q+t):t;
	}
}

int main()
{
	string text,pattern;
	int q=101;
//	cout<<"Enter Text and Pattern"<<endl;
//	getline(cin,text);
//	getline(cin,pattern);

	text = "THIS TEXT IS TEST TEXT";
	pattern = "TEXT";
	matchPattern(text,pattern,text.size(),pattern.size(),q);



}