#include<iostream>
#include<cstdlib>
#include<cmath>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

using namespace std;

int main()
{
	int N;
	cout<<"Enter money amount to find the permutation of all changes"<<endl;
	cin>>N;
	int changeList[] = {2,5};
	int c = sizeof(changeList)/sizeof(changeList[0]);
	int comboList[N+1][c+1] = {0};
//	for(int i=0;i<=N;++i)
//	{
//		for(int j=0;j<=c;j++)
//			cout<<comboList[N][c]<<"\t"	;
//		cout<<endl;
//	}

	for(int i=0;i<=c;++i)
		comboList[0][i]=1;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=c;++j)
			comboList[i][j]		= 	comboList[i][j-1] +  ((i-changeList[j-1])>=0?comboList[i-changeList[j-1]][j]:0)	;
		
	cout<<"Total permutation possible = "<<comboList[N][c]<<endl;
	
	
}