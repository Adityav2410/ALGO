#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;


int main()
{
	string str;
	
	cout<<"Enter string"<<endl;
	cin>>str;
	int front = 0,rear = str.length()-1;
	bool flag=true;
	int edit=0;

	if( rear%2) 
		cout<<"The string has even number of digits"<<endl;

	while(front<rear)
	{
		if(str[front] == str[rear])
		{	++front ; 	--rear;		}
		else if( edit == 1)
		{	edit = 2;	break;	}
		else
		{
			if(rear-front<1)
			{	edit = 2;	break;		}
			else
			{
				if(str[front+1]==str[rear])
					++front;
				else if(str[front]==str[rear-1])
					--rear;
				else
				{	edit = 2;	break;	}

			}
		}
	}//whille
	if(edit==2)
		cout<<"FAIL: String cannot be converted to palindrome with 1 edit"<<endl;
	else if(edit ==1 )
		cout<<"PASS: String can be converted to palindrome with 1 edit"<<endl;
	else if(edit == 0 && front == rear)
		cout<<"String can be edited to convert to palindrome"<<endl;
	else if( edit == 0 && front != rear)
		cout<<"String is already palindrome"<<endl;
} //main