#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;

#define NUMBER_OF_CHAR 256

void generateStateMachine(string pattern,int M,int state[][NUMBER_OF_CHAR])
{
	for(int i=0;i<NUMBER_OF_CHAR;++i)
		state[0][i] = 0;
	state[0][pattern[0]] = 1;

	int lps = 0;

	for(int i=1;i<=M;++i)
	{
		for(int x=0;x<NUMBER_OF_CHAR;++x)
			state[i][x] = state[lps][x];
		
		state[i][pattern[i]]=i+1;

		// define lcs for next row
		if(i<M)
			lps = state[lps][pattern[i]];
	}

	

}//generateStateMachine

void finiteAutomataSearch(string text, string pattern, int N,int M)
{
	int state[M+1][NUMBER_OF_CHAR];
	generateStateMachine(pattern,M,state);
	int st = 0;
	for(int i=0;i<N;++i)
	{
		st = state[st][text[i]];
		if(st == M)
			cout<<"Pattern found at "<<i-M+1<<endl;
	}
}


int main()
{
	string text,pattern;
	text = "THIS TEXT IS TEST TEXT";
	pattern = "TEXT";

	finiteAutomataSearch(text,pattern,text.length(),pattern.length());

}//main