#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int * createZarray( string list)
{
	cout<<"The string is\n"<<list<<endl;
	
	int z_value[list.size()] = {0};
	int l=r=0;
	for(int i=1;i<list.size();++i)
	{
		if(l < i && r < i)
		{
			
		}

	}

}


int main()
{
	string text,pattern;
	 
	cout<<"Enter Text and Pattern"<<endl;
	getline(cin,text);	getline(cin,pattern);
	//int Z_arr[text.size()+pattern.size()+1];
	int * Z_arr = createZarray(text+"$"+pattern);



}