#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
//#include<

using namespace std;

double calculatePower(int x, int y)
{
	if(y ==0)
		return(1);
	if(y==1)
		return(x);

	double temp = calculatePower(x,y/2);

	if(y%2==0)
		return(temp*temp);
	else
		return(y>0?temp*temp*x:temp*temp/x);
}

int main()
{
	int x,y;
	cout<<"Enter x and y"<<endl;
	cin>>x>>y;

	double power = calculatePower(x,y);
	cout<<"x^y = "<<power<<endl;
}