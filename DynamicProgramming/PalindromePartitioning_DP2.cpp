#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>


using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int findminPalPartition(string str, int len)
{
	bool checkPal[len+1][len+1];

	for(int i=0;i<=len;++i)
		checkPal[i][i]=true;
	
	for(int l=2;l<=len;++l)
	{
		for(int i=1;i<=len-l+1;++i)
		{
			int j = i+l-1;
			if(l==2)
				checkPal[i][j]=(str[i-1]==str[j-1]);
			else
				checkPal[i][j] = (checkPal[i+1][j-1]) && (str[i-1]==str[j-1]);
		}
	}

	for(int i=1;i<=len;++i)
	{
		for(int j=1;j<=len;++j)
			cout<<checkPal[i][j]<<"\t";
		cout<<endl<<endl;
	}

	unsigned int cutCount[len+1];
	for(int i=1;i<=len;++i)
	{
		if(checkPal[1][i])
			cutCount[i]=0;	
		else
		{	
			cutCount[i]=INT_MAX;
			for(int j=1;j<i;++j)
				if(checkPal[j+1][i]==true)
					cutCount[i]= min(cutCount[i],cutCount[j]+1);
		}
	}


	for(int i=1;i<=len;++i)
		cout<<cutCount[i]<<"\t";

	return(cutCount[len]);

}


int main()
{
	string str = "ABABCAAC";
	int minPartition = findminPalPartition(str, str.length());
	cout<<"Minimum number of partitions needed =" <<minPartition<<endl;


} //main