#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void RabinKarpSearch(string text,string pattern,int N, int M,int q)
{
	int tK=0,pK=0,h=1,D=256;
	int i,j;
	for(i=0;i<M;++i)
	{
		pK = (D*pK + pattern[i])%q;
		tK = (D*tK + text[i])%q;
	}
//	cout<<"Pattern Key = "<<pK<<endl;
//	cout<<"First Text key "<<tK<<endl;
	for(int i=0;i<M-1;++i)
		h = (D*h)%q;

	for(i=0;i<=N-M;++i)
	{	
		if(tK == pK && text[i]==pattern[0])
		{
			for(j=1;j<M;++j)
				if(text[i+j] != pattern[j])
					break;
			if(j==M)
				cout<<endl<<"Pattern found at "<<i<<endl;	
		}
		if(i< N-M)
			tK = ( D*(tK-h*text[i]) + text[i+M])%q;
		tK = tK<0?tK+q:tK;
	}
	cout<<endl;
}


int main()
{	
	string text = "THIS TEXT IS TEST TEXT";
	string pattern = "TEXT";
	int q=101;
	RabinKarpSearch(text,pattern,text.length(),pattern.length(),q);
}