#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int a[], int N)
{
	for(int i=0; i<N;++i)
		cout<<a[i]<<"\t";
	cout<<endl;
}

void quickSort(int a[], int l, int r,int N)
{



	if( l>= r)
		return;

	int pivot = a[r];
	int pindex = l;

	//cout<<"Array: \tl="<<l<<"\tr="<<r<<"\t Pivot="<<pivot<<endl;
	//printArray(a,N);
	//getchar();

	for(int i=l;i<=r;++i)
	{
		if(a[i] < pivot)
		{
			swap(a[i],a[pindex]);
			++pindex;
		}
	}
	swap(a[r],a[pindex]);

	quickSort(a, l, pindex-1,N);
	quickSort(a, pindex+1, r,N);

}

int main()
{
	int a[] = {30, 80, 10, 90, 40, 50, 70};
	int N = sizeof(a)/sizeof(a[0]);

	quickSort(a,0,N-1,N);
	
	for(int i=0; i<N;++i)
		cout<<a[i]<<"\t";
	cout<<endl;

}