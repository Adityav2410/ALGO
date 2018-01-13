/* 
URLify
Write a method to replace all spaces in a string with '%20'. 
You may assume that the string has sufficiend space at the end to hold the additional characters,
and that you are given the "true" length of of the string. 


Eg.
Input:		"Mr John Smith    " , 13
Output:		"Mr%20John%20Smith"
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;

int main(){
	// get inputs
	string s;
	int tLength;
	bool demo = true;

	// there are bugs in accepting user input so the code can be used in demo mode
	if( demo ){
		s = "Aditya Raj Verma test code        ";
		tLength = 26;
		cout<<"Input string: \t"<<s<<endl;;
		cout<<"True length: \t"<<tLength<<endl;
	}
	else{
		cout<<"Enter string with spaces "<<endl;
		cin>>s;
		cout<<"Length of string: "<<s.length()<<endl;
		cout<<"Enter true length of string"<<endl;
		cin>>tLength;
	}


	// start manipulation of string
	int spaceIndex = s.length()-1;
	int lastCharIndex  = tLength -1;

	while( lastCharIndex >= 0 && lastCharIndex < spaceIndex){
		if( s[lastCharIndex] == ' '){
			lastCharIndex--;
			s[spaceIndex--] = '0';
			s[spaceIndex--] = '2';
			s[spaceIndex--] = '%';

		}else{
			s[spaceIndex--] = s[lastCharIndex--] ;
		}
	}
	cout<<"URLified string: "<<s<<endl;
}
