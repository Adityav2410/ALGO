#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>


using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int findInsertionIndex(int lis[],int num, int l, int r)
{
	while(l<r)
	{
		if( lis[(l+r)/2] <= num )
			l= (l+r)/2+1;
		else
			r = (l+r)/2;
	}
}


int calculateLISlength(int list[],int len)
{
	int lis[len+1]={0};		lis[1]=list[0];		int length = 1;	
	
	for(int i=2;i<=len;++i)
	{
		if(list[i-1]>lis[length])
		{
			++length;	lis[length] = list[i-1];
		}
		else
		{
			int index = findInsertionIndex(lis,list[i-1],0,length);
			lis[index] = list[i-1];
		}
	}

	for(int i=1;i<=length;++i)
		cout<<lis[i]<<"\t";


	cout<<"Maximum Length of LIS = "<<length<<endl;
	return(length);
}



int main()
{
	int list[] = {1,3,2,14,5,6,3};
	int maxLis = calculateLISlength(list, sizeof(list)/sizeof(list[0]));
	cout<<"LIS in the array = "<<maxLis<<endl;

}