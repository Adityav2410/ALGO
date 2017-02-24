#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

string swapCharacters(string s, int c1,int c2)
{
	char temp = s[c1];
	s[c1] = s[c2];
	s[c2] = temp;

	return(s);
}

int calculationNumberOfPermutation(string s,int front,int endIndex)
{
	if(endIndex==-1)
		return(0);
	if(endIndex-front==0)
	{	cout<<s<<endl;	return(1);	}
	
	int count = 0 ;
	for(int i=front;i<=endIndex;++i)
	{
		
		s = swapCharacters(s,front,i);
		count+=calculationNumberOfPermutation(s,front+1,endIndex);
		s = swapCharacters(s,front,i);
	}
	return(count);
}


int main()
{
	string s;
	cout<<"Enter String"<<endl;
	getline(cin,s);

	int permutationCount = calculationNumberOfPermutation(s,0,s.length()-1);
	cout<<"Number of permutation of given word = "<<permutationCount<<endl;
} //main
