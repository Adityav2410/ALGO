#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

double getMedian(int list1[], int list2[], int N)
{

	if(N==2)
	{
		cout<<"List1: "<<list1[0]<<"\t"<<list1[N-1]<<endl;
		cout<<"List2: "<<list2[0]<<"\t"<<list2[N-1]<<endl;
	}



	if(N == 1)
		return( (list1[0] + list2[0]) /2);
	if( N == 2 )
		return( (max(list1[0],list2[0]) + min(list1[1],list2[1]))/2.0 );

	double m1 = N%2?list1[N/2]:(list1[N/2]+list1[N/2-1])/2.0;
	double m2 = N%2?list2[N/2]:(list2[N/2]+list2[N/2-1])/2.0;

	if(N==5)
		cout<<"m1="<<m1<<"\t m2="<<m2<<endl;


	if(m1 == m2)
		return(m1);
	int x = ceill(N/2.0);
	if(m1 > m2)
		return( getMedian(list1,&list2[x],(int)N/2));
	else
		return(getMedian( &list1[x], list2,(int)N/2));
}//getMedian

int main()
{
	int list1[] = {1, 2, 3, 6,15};
    int list2[] = {4, 5, 8, 10,12};

	int N = sizeof(list1)/sizeof(list1[0]);

	double median = getMedian(list1, list2, N);
	cout<<"Median of List = "<<median<<endl;

}//main