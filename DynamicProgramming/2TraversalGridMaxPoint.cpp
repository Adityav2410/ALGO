#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

#define R 5
#define C 4

bool isValid(int r, int c1, int c2)
{
	return( r>=0 && r<R && c1>=0 && c1<C && c2>=0 && c2<C);
}

int getMaxUtil(int arr[R][C],int mem[R][C][C],int r, int c1, int c2)
{
	if(!isValid(r,c1,c2))
		return(INT_MIN);
	if(mem[r][c1][c2]!=-1)				// if the path has already been visited
		return(mem[r][c1][c2]);
	
	if(r==R-1 && c1==0 && c2==C-1)		// if at the right end positions
	{	return(arr[r][c1]+ arr[r][c2]);		}
	if(r == R-1 && (c1!=0 || c2!=C-1) )
	{	return(INT_MIN);					}

	int temp = (c1==c2)?arr[r][c1]:(arr[r][c1]+arr[r][c2]);
	int ans = INT_MIN;
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1-1,c2-1));
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1-1,c2+0));
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1-1,c2+1));
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1+0,c2-1));
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1+0,c2+0));
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1+0,c2+1));
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1+1,c2-1));
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1+1,c2+0));
	ans = max(ans,temp+getMaxUtil(arr,mem,r+1,c1+1,c2+1));

	mem[r][c1][c2] = ans;
	return(ans);
} //getMaxUtil


int calculate2TraversalMaxPoint(int arr[R][C])
{
	int mem[R][C][C];
	memset(mem,-1,sizeof(mem));

	return( getMaxUtil(arr, mem, 0, 0, C-1) );
}

int main()
{
    int arr[R][C] = {{3, 6, 8, 2},
                    {5, 2, 4, 3},
                    {1, 1, 20, 10},
                    {1, 1, 20, 10},
                    {1, 1, 20, 10},
                   };

    int maxTraversalPoint = calculate2TraversalMaxPoint(arr);               
    cout<<"Max 2 Traversal point of grid = "<<maxTraversalPoint<<endl;
} //main