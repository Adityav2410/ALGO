#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int mergeSubArray(int arr[], int start, int mid, int end, int temp[])
{
	int i=start;
	int j = mid+1;
	int k = 0;
	int invCount = 0;
	
	while( i<= mid && j<= end)
	{
		if( arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			invCount += mid-i+1;
		}
	}

	while( i<= mid)
		temp[k++] = arr[i++];
	while(j<= end)
		temp[k++] = arr[j++];

	for(int i=0; i<=end-start; ++i )
		arr[start+i] = temp[i];

	return(invCount);
}//mergeSubArray


int countInversionPair(int arr[], int start, int end)
{
	if( end <= start)
		return(0);

	int mid = (start+end)/2;
	int inv1 = countInversionPair(arr, start, mid);
	int inv2 = countInversionPair(arr, mid+1, end);

	int * temp = new int[end-start+1];
	int mergeInv = mergeSubArray(arr,start, mid, end, temp);
	return( inv1 + inv2 + mergeInv);
}



int mergeSort(int arr[], int N)
{
	return( countInversionPair(arr,0,N-1));
}//mergeSort


int main()
{
  int arr[] = {1, 20, 6, 4, 5};
  printf(" Number of inversions are %d \n", mergeSort(arr, sizeof(arr)/sizeof(arr[0])));

  for(int i=0; i< sizeof(arr)/sizeof(arr[0]); ++i)
  	cout<<arr[i]<<"\t";
  cout<<endl;

  getchar();
  return 0;
}//main