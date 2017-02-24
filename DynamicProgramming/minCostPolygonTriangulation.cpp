#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

struct points
{
	int x,y;
};

double cost(struct points coordList[],int i, int j, int k)
{
	double dist1 = sqrt( pow(coordList[i].x-coordList[j].x,2)+ pow(coordList[i].y-coordList[j].y,2) );
	double dist2 = sqrt( pow(coordList[i].x-coordList[k].x,2)+ pow(coordList[i].y-coordList[k].y,2) );
	double dist3 = sqrt( pow(coordList[k].x-coordList[j].x,2)+ pow(coordList[k].y-coordList[j].y,2) );
	return(dist1+dist2+dist3);
}


double findMinTriangulationCost(struct points coordList[],int N)
{
	if(N<=3)
		return(0);
	double minCost[N][N]={0};
	for(int l=1;l<=N;++l)
		for(int i=0;i<N-l+1;++i)
		{
			int j=i+l-1;	minCost[i][j]=INT_MAX;
			if(j<i+2)
				minCost[i][j]=0;
			else if(j==i+2)
				minCost[i][j] = cost(coordList,i,i+1,i+2);
			else
				for(int k=i+1;k<j;++k)
					minCost[i][j] = min( minCost[i][j] , minCost[i][k]+minCost[k][j] + cost(coordList,i,j,k));
		}		

		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
				cout<<minCost[i][j]<<"\t";
			cout<<endl;
		}	

	return( minCost[0][N-1]);			
}//findMinTriangulationCost


int main()
{
	struct points coordList[] = {{0,0},{1,0},{2,1},{1,2},{0,2}};
	double minCost = findMinTriangulationCost(coordList,sizeof(coordList)/sizeof(coordList[0]));
	cout<<"Minimum Triangulation Cost = "<<minCost<<endl;
} //main