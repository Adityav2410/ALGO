#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;


int minEggFloorTrial(int n,int k)
{
	if(k==0 || k==0)
		return k;
	if(n==1)
		return(k);


	int minTrial=INT_MAX;
	for(int i=1;i<=k;++i)
	{
		int trial = 1 + max( minEggFloorTrial(n-1,i-1),minEggFloorTrial(n,k-i) );
		minTrial = min(minTrial,trial);

	}
	return(minTrial);

} //minEggFloorTrial


int main()
{
	int n,k;
	cout<<"Enter N-no of eggs and K-no of floors"<<endl;
	cin>>n>>k;
	int minTrial = minEggFloorTrial(n,k);
	cout<<"Minimum no of trial needed = "<<minTrial<<endl;

}//main
