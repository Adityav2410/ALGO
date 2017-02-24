#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

struct dual
{
	int a,b;
};

int maxIncreasingPairLength(struct dual list[],int len)
{
	int lis[len+1];
	for(int i=1;i<=len;++i)
	{
		lis[i]=1;
		for(int j=1;j<i;++j)
		{
			if(list[j-1].b<list[i-1].b)
				lis[i]=max(lis[j]+1,lis[i]);
		}
	}

	for(int i=1;i<=len;++i)
		cout<<lis[i]<<"\t";

	return(lis[len]);
}


int main()
{
	struct dual list[] = { {5,25},{15,25},{27,40},{50,60} };
	int maxLength = maxIncreasingPairLength( list, sizeof(list)/sizeof(list[0]));
	cout<<"Lis = "<<maxLength<<endl;
}//main