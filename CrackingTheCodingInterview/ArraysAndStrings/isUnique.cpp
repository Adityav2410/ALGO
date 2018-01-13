/*
is Unique

Implement algorithm to determine if a string has all unique characters. 
What if you cannot use additional data strutures?
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

int main(){
	// process input
	string s;
	cout<<"Enter string "<<endl;
	cin>>s;

	// check for duplicacy
	bool duplicacy = false;
	vector<bool> present(128, false);
	for( auto c : s ){
		// cout<<"Checking character: "<<c<<"\t previous status: "<<present[c-'a']<<endl;
		if(present[c]){
			cout<<"Duplicate characters present in string"<<endl;
			duplicacy = true;
			break;
		}
		else{
			present[c] = true;
		}
	}
	if( !duplicacy )
		cout<<"All characters in string are unique "<<endl;
} //main