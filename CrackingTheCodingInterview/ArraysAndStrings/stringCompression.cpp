/*
String compression:
Implement a method to perform basic string compression using the counts of repeated characters. 
For example, the string aabccccaaa would become a2b1c5a3. 
If the "compresssed" string would not become smaller than the original string, 
your method should return the original string. 
You can assume the string has only uppercase and lowercase letters(a-z)
*/


#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<algorithm>

using namespace std;

int getNumberOfDigitsInNumber(int num){
	int nDigit = 0;
	while( num > 0 ){
		nDigit += 1;
		num /= 10;
	}
	return nDigit;
}

int getLengthOfCompressedString(string str){
	int l_compressedString = 0;
	for(int i = 0; i < str.length(); ){
		int j = i+1;
		for( ; j < str.length(); ++j)
			if( str[j] != str[i] )
				break;
		// j points to an index, s.t. jth char != ith char
		l_compressedString += 1 + getNumberOfDigitsInNumber(j-i);
		i = j;
	}
	return l_compressedString;
}

int main(){

	// get inputs
	string str;
	cout<<"Enter string "<<endl;
	cin>>str;
	int l_inputString = str.length();

	// compress string
	int l_compressedString = getLengthOfCompressedString(str);
	if(l_compressedString > l_inputString ){
		cout<<"No advantage of compression: \t Original string: "<<str<<endl;
	}else{		// compress string
		string res(l_compressedString,' ');
		int destIndex = 0;
		for(int i = 0; i < str.length(); ){
			int j = i+1;
			for( ; j < str.length(); ++j)
				if( str[j] != str[i] )
					break;
			// j points to an index, s.t. jth char != ith char
			res[destIndex++] = str[i];
			for(auto c : to_string(j-i) )
				res[destIndex++] = c;
			i = j;
		}
		cout<<"Compressed string: \t"<<res<<endl;
	}
}