#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<climits>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)


void printUglyNumbers(int N)
{
	int ugly[N];	ugly[0]=1;
	int i2=0,i3=0,i5=0;
	for(int i=1;i<N;++i)
	{
		int ugly_next = min( min(ugly[i2]*2, ugly[i3]*3), ugly[i5]*5);
		if(ugly_next == ugly[i2]*2)
			i2++;
		if(ugly_next == ugly[i3]*3)
			i3++;
		if(ugly_next == ugly[i5]*5)
			i5++;

		ugly[i] = ugly_next;
	}

	for(int i=0;i<N;++i)
		cout<<ugly[i]<<"\t";

	cout<<endl;

}

int main()
{
	int N;
	cout<<"Enter the number of UGLY number to be printed"<<endl;
	cin>>N;
	printUglyNumbers(N);
}