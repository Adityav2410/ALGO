#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void printWordWrap(int p[],int numberOfWords)
{
	if(p[numberOfWords]>1)
		printWordWrap(p,p[numberOfWords]-1);
	cout<<"Word Index:\t From: "<<p[numberOfWords]<<"\tto: "<<numberOfWords<<endl;
}


void calculateAndPrintLineCost(int wordLength[],int lineLength,int numberOfWords)
{
	int extraSpace[numberOfWords+1][numberOfWords+1] = {0};
	for(int i=1;i<=numberOfWords;++i)
		extraSpace[i][i-1]=lineLength;

	unsigned int extraSpaceCost[numberOfWords+1][numberOfWords+1] = {0};
	for(int i=1;i<=numberOfWords;++i)
		for(int j=i;j<=numberOfWords;++j)
		{	
			extraSpace[i][j] = extraSpace[i][j-1] - (wordLength[j-1] );// + (j-i)>0?1:0);
			if( j>i)
				extraSpace[i][j]-= 1;
			extraSpaceCost[i][j] = extraSpace[i][j] >= 0 ? pow(extraSpace[i][j],2) : INT_MAX;
		}

	
	unsigned int c[numberOfWords+1] = {INT_MAX};	c[0]=0;
	int p[numberOfWords+1];
	for(int i=0;i<=numberOfWords;++i)
		p[i]=1;

	for(int i=1;i<=numberOfWords;++i)
	{
		c[i] = extraSpaceCost[1][i];
		for(int j=1;j<i;++j)
		{
			if( c[j] + extraSpaceCost[j+1][i] < c[i] )
			{
				c[i] = c[j]+extraSpaceCost[j+1][i];
				p[i] = j+1;	
			} 
			
		}
	}

	printWordWrap(p,numberOfWords);

	for(int i=1;i<=numberOfWords;++i)
		cout<<c[i]<<"\t";
	cout<<endl;

}//calculateAndPrintLineCost

int main()
{
	int wordLength[] = {3,2,2,5};
	int lineLength = 6;
	int numberOfWords = sizeof(wordLength)/sizeof(wordLength[0]);
	calculateAndPrintLineCost(wordLength, lineLength, numberOfWords); 

} //main