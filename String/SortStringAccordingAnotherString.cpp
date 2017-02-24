#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<map>

using namespace std;

void generateMapForPattern( map<char,int> &sortSequence,string pattern)
{
	for(int i=0;i<pattern.length();++i)
		sortSequence[pattern[i]] = 0;
}

string sortString( map<char,int> &sortSequence, string pattern,string text)
{
	string sortString="";
	for(int i=0;i<text.length();++i)
		++sortSequence[text[i]];

	for(int i=0; i<pattern.length();++i)
		for(int j=1;j<=sortSequence[pattern[i]] ;++j)
			sortString+=pattern[i];

	return sortString;	
}

int main()
{
	string patt,text;
	cout<<"Enter Pattern which defines sorting sequence"<<endl;
	cin>>patt;
	cout<<"Enter Text to be sorted"<<endl;
	cin>>text;
	map<char,int> sortSequence;	generateMapForPattern(sortSequence,patt);
	string text_sorted = sortString(sortSequence,patt,text);
	cout<<"Sorted String :- "<<endl;
	cout<<text_sorted<<endl;

}