/* 
One Away: There are three types of edits that can be performed on strings: 
insert a character, remove a character, or replace a character. 
Given two strings, write a function to check if they are one edit(or zero edits) away
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;

int getEditDistance(string s1, string s2, int l1, int l2){
	int retVal = 0;
	if( abs(l1 - l2) > 1){
		retVal = 2;
	}
	else if(l1 == 0 || l2 == 0 ){
		retVal = abs(l1-l2);
	}
	else if( s1[l1-1] == s2[l2-1] ){
		retVal = getEditDistance(s1, s2, l1-1, l2-1);
		// cout<<"l1="<<l1<<"\t l2="<<l2<<"\t Last char same: \t editDistance="<<retVal<<endl;
	}
	else{
		retVal = 1 + min( getEditDistance(s1, s2, l1-1, l2-1),
						min(getEditDistance(s1, s2, l1-1, l2), getEditDistance(s1, s2, l1, l2-1))
					);
		// cout<<"l1="<<l1<<"\t l2="<<l2<<"\t Last char different: \t editDistance="<<retVal<<endl;
	}
	// cout<<"l1="<<l1<<"\t l2="<<l2<<"\t editDistance="<<retVal<<endl;
	return retVal;
}

int main(){

	// take inputs
	string str1, str2;
	cout<<"Enter string 1"<<endl;
	cin>>str1;
	cout<<"Enter string 2"<<endl;
	cin>>str2;
	int length1 = str1.length(), length2 = str2.length();

	// check for edit distances
	int editDistance = getEditDistance(str1, str2, length1, length2);
	if( editDistance > 1 )
		cout<<"Fail:\t Edit distance greater than 1"<<endl;
	else
		cout<<"Pass:\t Edit distance = "<<editDistance<<endl;




} //main