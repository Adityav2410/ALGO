#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;

int possibleNonConsecutive1permutation(int N)
{
	int possibility[N+1];
	possibility[1] = 2;	possibility[2] = 3;
	for(int i=3;i<=N;++i)
		possibility[i] = possibility[i-1]+possibility[i-2];

	return(possibility[N]);


}


int main()
{
	int N;
	cout<<"Enter N"<<endl;
	cin>>N;

	cout<<"The number of permutation with non-consecutive 1 = "<<possibleNonConsecutive1permutation(N)<<endl;
} //main