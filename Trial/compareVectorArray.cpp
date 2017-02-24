#include<iostream>
#include<vector>
#include<ctime>


using namespace std;

int main()
{
	
	int N = 2000000;
	int c1,c2;

	double execTime;


	c1 = clock();
	int arr[N] = {0};
	c2 = clock();
	execTime = (c2-c1)/double(CLOCKS_PER_SEC)*1000;
	cout<<"Array Initialization time = "<<execTime<<endl;

	c1 = clock();
	vector<int> vect(N,0);
	c2 = clock();
	execTime = (c2-c1)/double(CLOCKS_PER_SEC)*1000;
	cout<<"Vector Initialization time = "<<execTime<<endl;

	c1 = clock();
	for(int i=0;i<N;++i)
		arr[i]=i;
	c2 = clock();
	execTime = (c2-c1)/double(CLOCKS_PER_SEC)*1000;
	cout<<"Array access time = "<<execTime<<endl;

	c1 = clock();
	for(int i=0;i<N;++i)
		vect[i]=i;
	c2 = clock();
	execTime = (c2-c1)/double(CLOCKS_PER_SEC)*1000;
	cout<<"Vector access time = "<<execTime<<endl;

	cout<<"Clocks per sec = "<<CLOCKS_PER_SEC<<endl;

}