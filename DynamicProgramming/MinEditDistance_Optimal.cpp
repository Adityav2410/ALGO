#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

int computeMinEditDistance(string s1, string s2, int l1, int l2)
{

	if( l1 == -1 && l2 == -1)
		return 0;
	if( l1 == -1 || l2 == -1 )
		return max(l1,l2)+1 ;

	if(s1.at(l1) == s2.at(l2))
		return( computeMinEditDistance(s1,s2,l1-1,l2-1));

	return( min(	computeMinEditDistance(s1,s2,l1,l2-1)   +1 , 				//insert
			min(	computeMinEditDistance(s1,s2,l1-1,l2)   +1 , 		//delete
					computeMinEditDistance(s1,s2,l1-1,l2-1) +1 	) ) 		//replace
			); // return

}


int main()
{
	string s1,s2;
	cout<<"Enter two string "<<endl;
	cin>>s1>>s2;
	int minEditDistance = computeMinEditDistance(s1,s2,s1.length()-1,s2.length()-1);
	cout<<"Min Edit distance between "<<s1<<" and "<<s2<<" = "<<minEditDistance<<endl;
}