#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int compareCharacter(void * p1, void * p2)
{
	return( *(char *)p1 - *(char *)p2  );
}

string swapCharacters(string s, int p1, int p2)
{
	char temp = s[p1];
	s[p1] = s[p2];
	s[p2] = temp;
	return(s);
}

int generatePermutationsofWords(string s,int first)
{
	if(s.length() == 0)
		return(0);
	if(s.length()-first==1)
	{	return(1);			}

	sort(s.begin()+first,s.end());
	cout<<"Sorted String = "<<s<<endl;
	int count=0;
	for(int i=first;i<s.length();++i)
	{
		if(i==first)
			count += generatePermutationsofWords(s,first+1);
		else
		{
			if(s[i]!=s[first])
			{
				s = swapCharacters(s,first,i);
				count += generatePermutationsofWords(s,first+1);
			}
		}
	}
	return(count);
}


int main()
{
	string s;
	cout<<"Enter WORD"<<endl;
	getline(cin, s);
	int permute = generatePermutationsofWords(s,0);
	cout<<"Number of nom-duplicate permutation of words= "<<permute<<endl;
}