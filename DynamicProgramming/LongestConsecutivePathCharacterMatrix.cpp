#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

#define R 3
#define C 3

int getCurrentPathLength(char mat[R][C], int currentPathLength[R][C],int r,int c)
{
	if(currentPathLength[r][c]!=-1)
		return(currentPathLength[r][c]);
	currentPathLength[r][c]=1;
	if(r==0 && c==0)
		cout<<"First index. Initialize path length = "<<currentPathLength[r][c]<<endl;


	int rowMove[] = {0,-1,-1,-1,0,1,1,1};
	int colMove[] = {-1,-1,0,1,1,1,0,-1};

	int nro, nco;
	for(int i=0;i<8;++i)
	{ 
		nro = r+rowMove[i];
		nco = c+colMove[i];

		if( nro >=0 && nro <R && nco>=0 && nco < C && mat[nro][nco]==mat[r][c]+1)
		{	
			if(r == 0 & c==0)
				cout<<"Next char found "<<mat[nro][nco]<<" Movement = "<<i<<"new indices = "<<nro<<","<<nco<<endl;
			currentPathLength[nro][nco] = getCurrentPathLength(mat,currentPathLength,nro,nco) ;
			currentPathLength[r][c] = 1 + currentPathLength[nro][nco];
			break;
		}
	}

	return(currentPathLength[r][c]);



} // getCurrentPathLength

int getMaxLength(char mat[R][C])
{
	int currentPathLength[R][C]; 
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			currentPathLength[i][j]=-1;

	int maxLength = INT_MIN;
	
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			maxLength = max( maxLength, getCurrentPathLength(mat,currentPathLength,i,j) );

	for(int i=0;i<R;++i)
	{	
		for(int j=0;j<C;++j)
			cout<<mat[i][j]<<"\t";
		cout<<endl;
	}

	cout<<endl<<endl<<endl;

	for(int i=0;i<R;++i)
	{	
		for(int j=0;j<C;++j)
			cout<<currentPathLength[i][j]<<"\t";
		cout<<endl;
	}
		

	return(maxLength);

}//getMaxLength



int main()
{
	//char mat[R][C] = { 	 { 'a','c','d'},
    //	                 { 'h','b','e'},
    //	                 { 'i','g','f'}
    //	             };

	char mat[R][C] = { {'b', 'e', 'f'},
                     {'h', 'd', 'a'},
                     {'i', 'c', 'a'}};    	             

    int maxLength = getMaxLength(mat);	             
    cout<<"Max Length in the character matrix = "<<maxLength<<endl;
} //main