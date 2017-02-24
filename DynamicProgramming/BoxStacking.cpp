#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string>


using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

struct Box
{	
	int h,b,d;
};// Box


int compareBox(const void *BoxA,const void * BoxB)
{
	return (*(Box *)BoxB).b * (*(Box *)BoxB).d - (*(Box *)BoxA).b * (*(Box *)BoxA).d ;
}

int calculateMaxBoxStackingHeight(struct Box BoxDimension[],int numBox)
{
	struct Box boxStack[numBox*3+1];
	for(int i=1;i<=numBox;++i)
	{
		boxStack[3*(i-1)+1].h = BoxDimension[i-1].h;
		boxStack[3*(i-1)+1].b = max(BoxDimension[i-1].b,BoxDimension[i-1].d);
		boxStack[3*(i-1)+1].d = min(BoxDimension[i-1].b,BoxDimension[i-1].d);

		boxStack[3*(i-1)+2].h = BoxDimension[i-1].b;
		boxStack[3*(i-1)+2].b = max(BoxDimension[i-1].h,BoxDimension[i-1].d);
		boxStack[3*(i-1)+2].d = min(BoxDimension[i-1].h,BoxDimension[i-1].d);

		boxStack[3*(i-1)+3].h = BoxDimension[i-1].d;
		boxStack[3*(i-1)+3].b = max(BoxDimension[i-1].h,BoxDimension[i-1].b);
		boxStack[3*(i-1)+3].d = min(BoxDimension[i-1].h,BoxDimension[i-1].b);
	}

	numBox*=3;

	qsort(boxStack+1,numBox,sizeof(BoxDimension[0]),compareBox);

	unsigned int heightStack[numBox+1];
	unsigned int belowFloor[numBox+1];
	for(int i=1;i<=numBox;++i)
	{
		heightStack[i]=boxStack[i].h;
		belowFloor[i] = 0;
		for(int j=1;j<i;++j)
		{
			if(boxStack[j].b > boxStack[i].b && boxStack[j].d > boxStack[i].d && heightStack[j]+boxStack[i].h > heightStack[i])
			{	heightStack[i] = heightStack[j] + boxStack[i].h ; 		belowFloor[i] = j;	}		
		}
	}


	unsigned int maxHeight = heightStack[1];
	for(int i=2;i<=numBox;++i)
		maxHeight = max(heightStack[i],maxHeight);


	return(maxHeight);

}


int main()
{
	struct Box BoxDimension[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
	int numBox = sizeof(BoxDimension)/sizeof(BoxDimension[0]);
	int maxHeight = calculateMaxBoxStackingHeight(BoxDimension,numBox);
	cout<<"Maximum Height of Box Stack = " <<maxHeight<<endl;
} //main