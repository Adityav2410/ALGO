/* 
Check Permutation: Given two strings, write a method to decide if one is a permutation of the other
*/


#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>
#include<vector>

using namespace std;

int main(){

	// accept input strings
	string s1, s2;
	cout<<"Enter string 1 "<<endl;
	cin>>s1;
	cout<<"Enter string 2"<<endl;
	cin>>s2;

	// check if two string are permutation of each other or not
	if( s1.length() != s2.length() ){
		cout<<"FAIL: Both string are not permutation of each other"<<endl;
	}else{
		bool permutation = true;
		vector<int> count(128, 0);
		// check frequency of each character for string 1
		for( auto c : s1 )
			count[c]++;
		for( auto c : s2 ){
			if( count[c] == 0 ){
				permutation = false;
				cout<<"FAIL: Both string are not permutation of each other"<<endl;
				break;
			}
		}
		if( permutation )
			cout<<"PASS: Both string are permutation of each other"<<endl;
	}
}//main