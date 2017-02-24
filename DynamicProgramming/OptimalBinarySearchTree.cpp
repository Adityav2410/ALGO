#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int FrequencySum(int freq[],int i, int j)
{
	int freqSum = 0;
	for(int k = i;k<=j;++k)
		freqSum+=freq[k];
	return freqSum;

} // FrequencySum

int optimalBinarySearchTree(int keys[],int freq[],int N)
{
	int searchTime[N][N] = {0};
	for(int i=0;i<N;++i)
		searchTime[i][i] = freq[i];

	for(int l=2;l<=N;++l)
	{
		for(int i=0;i<N-l+1;++i)
		{
			searchTime[i][i+l-1]=INT_MAX;
			int j=i+l-1;
			for(int k=i;k<=j;k++)
			{
				int c = FrequencySum(freq,i,j) + (k>i?searchTime[i][k-1]:0) + (k<j?searchTime[k+1][j]:0);
				if(c < searchTime[i][j])
					searchTime[i][j] = c;
			}
		}
	}


	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			cout<<searchTime[i][j]<<"\t";
		cout<<endl;
	}


	return searchTime[0][N-1];

}


int main()
{
	int keys[] = {10,12,20};
	int freq[] = {34,8,50};
	int N = sizeof(keys)/sizeof(keys[0]);
	int minimalSearchTime = optimalBinarySearchTree(keys, freq, N);

	cout<<"The minimal Search time for optimal Binary Search tree = "<<minimalSearchTime<<endl;

}//main
