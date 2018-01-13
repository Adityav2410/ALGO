/* 
Palindrome permutation
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

int main(){
	// get inputs
	string s(8,' '), length;
	cout<<"Enter string "<<endl;
	getline(cin,s );
	length = s.length();

	// check if permutation is palindrome or not
	vector<int> count(128, 0);
	for(auto c : s){
		if( c == ' ')
			continue;
		char indexChar = c>'Z'?c:c+32;
		// cout<<"Input char: "<<c<<"\t outChar: "<<indexChar<<endl;

		count[ indexChar ]++;
	} // get frequency of all characters in string

	// count of number of characters present odd number of times -there can be max of 1 char occuring odd times
	int oddCount = 0;
	for(auto x : count ){
		if( x %2 == 1 ) // if count is odd
			oddCount++;
		if( oddCount > 1 ){
			cout<<"Fail: Not a valid palindrome permutation"<<endl;
			break;
		}
	}
	if( oddCount <= 1 )
		cout<<"Pass: Valid palindrome permutation"<<endl;
}