#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>


using namespace std;

int numberOfnonDecreasingPermutation(int N)
{
	int count[10][N+1];
	
	for(int i=0;i<10;++i)
		for(int j=0;j<=N;++j)
			count[i][j]=0;
	
	for(int i=0;i<10;++i)
		count[i][1] = 1;

	for(int j=2;j<=N;++j)
		for(int i=0;i<10;++i)
			for(int k=0;k<=i;++k)
				count[i][j] += count[k][j-1];

	int maxCount = 0;
	for(int i=0;i<10;++i)
		maxCount += count[i][N];		
	
	return(maxCount);	


}

int main()
{
	int N;
	cout<<"Enter number of digits"<<endl;
	cin>>N;
	int count = numberOfnonDecreasingPermutation(N);
	cout<<"The number of nonDecreasing permutation = "<<count<<endl;
}