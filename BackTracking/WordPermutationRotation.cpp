#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>
#include<algorithm>

using namespace std;


void generatePermutation(string str, string out, int &count)
{
	if(str.length()==0)
	{	cout<<out<<endl;	++count ; 	return;	}
	
	for(int i=0;i<str.length();++i)
	{
		generatePermutation(str.substr(1),out+str[0],count);
		rotate(str.begin(),str.begin()+1,str.end());
	}



}


int main()
{
	string str;
	cout<<"Enter string"<<endl;
	getline(cin,str);
	int count = 0;
	generatePermutation(str,"",count);
	cout<<"Number of permutation possible = "<<count<<endl;

} //main