#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;

string encodeString(string s)		// encode String - only supports Alphabets - small / case sensitive
{
	int odd_Frequency[26] ={0};
	int even_Frequency[26]={0};
	string encodedString = "";
	
	for(int i=0;i<s.length();++i)
		if(i&1)						// if position is odd
			++odd_Frequency[s[i]-'a'];
		else
			++even_Frequency[s[i]-'a'];
	
	for(int i=0;i<26;++i)
		encodedString+=to_string(even_Frequency[i])+"-"+to_string(odd_Frequency[i])+"-";

	return(encodedString);

} // encodeString


int main()
{
	string s1 = "ADITYA";
	string s2 = "ADABCD";
	string s3 = "IDAAYT";
	string s1_encode = encodeString(s1);
	string s2_encode = encodeString(s2);
	string s3_encode = encodeString(s3);
	cout<<s1_encode<<"\n"<<s2_encode<<"\n"<<s3_encode<<endl;
	if(!s1_encode.compare(s2_encode))
		cout<<"String 1 and string 2 are same"<<endl;
	else
		cout<<"String 1 and string 2 are different"<<endl;


	if(!s1_encode.compare(s3_encode))
		cout<<"String 1 and string 3 are same"<<endl;
	else
		cout<<"String 1 and string 3 are different"<<endl;

}
