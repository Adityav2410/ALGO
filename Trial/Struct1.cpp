#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

struct node
{
	int a; 
	int b;
}p;



int main()
{
	p = {5,15};
	struct node p1={10,20};
	p1.a = 5;
	p1.b = 3;
	cout<<p1.a<<" "<<p1.b<<endl;
	cout<<p.a<<" "<<p.b<<endl;


}//main