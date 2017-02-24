#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)


void maxPossibleStep(char keypad[4][3],int N)
{	// movement: no move, left, up, right, down: Updated coordinates
	int rowStep[] = {0,-1,0,1,0};
	int colStep[] = {0,0,-1,0,1};


	int maxStep[10][N+1]={0};
	
	for(int i=0;i<10;++i)
		for(int j=0;j<=N;++j)
			maxStep[i][j] = 0;
	for(int i=0;i<10;++i)
	{	maxStep[i][0]=0;	maxStep[i][1]=1;	}


	


	for(int l=2;l<=N;++l)
	{
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<3;++j)
			{
				if(keypad[i][j] != '*' && keypad[i][j] != '#')
				{
					int num = keypad[i][j]-'0';
					for(int move = 0;move<5;++move)
					{
						int nro = i+rowStep[move];
						int nco = j+colStep[move];
						if(nro >=0 && nro <= 3 && nco >=0 && nco <= 2 && keypad[nro][nco]!= '*' && keypad[nro][nco] != '#')
							maxStep[num][l] += maxStep[ keypad[nro][nco] - '0'][l-1];
					}
				}
			}
		}
	}
//	cout<<endl<<endl<<endl;
//
//	for(int i=0;i<10;++i)
//	{
//		for(int j=1;j<=N;++j)
//			cout<<maxStep[i][j]<<"\t";
//		cout<<endl;
//	}

	int totalStep = 0;
	for(int i=0;i<10;++i)
		totalStep += maxStep[i][N];

	cout<<"count of max possible length "<<N<<" : "<<totalStep<<endl;
}//maxPossibleStep


int main()
{
    char keypad[4][3] = {	{'1','2','3'},
					        {'4','5','6'},
					        {'7','8','9'},
					        {'*','0','#'}
    					};

   	int N;
   	cout<<"Enter the number of steps"<<endl;
   	cin>>N;
    maxPossibleStep(keypad,N);					
} 