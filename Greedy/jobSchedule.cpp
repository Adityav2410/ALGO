#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

struct Job
{
	char id;
	int dead;
	int profit;
};

bool comparator(Job a, Job b)
{
		return( a.profit > b.profit);
}


void printJobScheduling( Job arr[], int n)
{
	sort(arr,arr+n,comparator);
	vector<char> schedule (n+1,'0');

	for(int i=0; i<n;++i)
		cout<<arr[i].profit<<endl;


	for(int i= 0 ; i< n ; ++i)
	{
		Job curr = arr[i];
		for( int j = curr.dead>n?n:curr.dead; j >= 1; --j)
		{
			if(schedule[j] == '0')
			{	schedule[j] = curr.id;
				break;
			}	
		}
	}

	for(int i=0; i<n;++i)
		if(schedule[i] != '0')
			cout<<"i="<<i<<"\t"<<schedule[i]<<"\t";

	cout<<endl;	


}

int main()
{

   Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);
    return 0;


}
