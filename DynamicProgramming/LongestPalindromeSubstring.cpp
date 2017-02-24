#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void printLongestPalindromeSubstring(string str, int L)
{
	bool checkPalindrome[L][L] = {true};
	for(int i=0;i<L;++i)
		checkPalindrome[i][i] = true;

	int maxLength = 1;
	for(int l=2;l<=L;l++)
		for(int i=0;i<L-l+1;++i)
		{	
			int j=i+l-1;
			if(l==2)
				if(str[i]==str[i+1])
				{	checkPalindrome[i][i+1] = true;		maxLength = max(maxLength, l);	}
				else
					checkPalindrome[i][i+1] = false;
			else
			{	checkPalindrome[i][j] = (str[i]==str[j]) && ( checkPalindrome[i+1][j-1])	;
				maxLength = max( maxLength, l*checkPalindrome[i][j]);	
			}	
		}	

	cout<<"Max Palindrome subsequencec = "<<maxLength<<endl;

} //printLongestPalindromeSubstring


int main()
{
	string str = "forgeeksskeegfor";
	//str = "ababc";
	printLongestPalindromeSubstring(str,str.length());
}