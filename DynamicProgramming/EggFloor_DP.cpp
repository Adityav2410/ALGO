#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;

int minEggFloorTrial(int n,int k)
{
	int trial[n+1][k+1];
	for(int egg = 1 ; egg<=n;++egg)
	{
		for(int floor=0;floor<=k;++floor)
		{
			if(egg==1)
				trial[egg][floor] = floor;
			else if(floor == 1 || floor == 0)
				trial[egg][floor] = floor;
			else
			{	
				int minimumAttempt = INT_MAX;
				for(int firstStep=1;firstStep<=floor;++firstStep)
				{	
					int attempt = 1 + max(trial[egg-1][firstStep-1],trial[egg][floor-firstStep] );
					minimumAttempt = min(minimumAttempt,attempt);
				}
				trial[egg][floor] = minimumAttempt;
				}
		} // for total number of floors
	} // for number of eggs
	
	return trial[n][k];


} //minEggFloorTrial

int main()
{
	int n,k;
	cout<<"Enter N-number of eggs and K-number of floors"<<endl;
	cin>>n>>k;
	int minTrial=minEggFloorTrial(n,k);
	cout<<"Minimum number of trial neened in worst case = "<<minTrial<<endl;
}