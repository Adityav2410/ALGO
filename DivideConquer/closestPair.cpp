#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

struct Point
{
	int x;
	int y;
};

bool compareX(Point P1,Point P2)
{
	return(P1.x < P2.x);
}

bool compareY(Point P1, Point P2)
{
	return(P1.y < P2.y);
}

vector<Point> createStrip(Point P[], int start,int mid,int end, double d)
{
	vector<Point> strip;
	for(int i=start; i<end; ++i)
		if(abs((P[i].x) - P[mid].x) < d)
			strip.push_back(P[i]);

	sort(strip.begin(), strip.end(), compareY);	

	return(strip);
}

double distPoints(Point P1, Point P2)
{
	return(sqrt(pow(P1.x-P2.x,2)+pow(P1.y-P2.y,2)));
}

double minDist_Strip(vector<Point> strip, double d)
{
	double minDist = d;
	int N = strip.size();
	for(int i=0; i<N; ++i)
		for(int j= i+1; j<N && strip[j].y- strip[i].y < d; ++j)
			minDist = min(minDist, distPoints(strip[i],strip[j]));

	return(minDist);	
}


double closest_Utill(Point P[], int start, int end)
{
	if(end <= start)
		return(0);

	if(end-start == 1)
		return(distPoints(P[start],P[end]));

	int mid = (start+end)/2;
	double dl = closest_Utill(P, start, mid);
	double dr = closest_Utill(P, mid, end);

	double d = min(dl, dr);


	vector<Point> strip = createStrip(P, start,mid,end, d); 
	double minDist = minDist_Strip(strip, d);

	return(minDist);

}

double closest( Point P[], int N)
{
	sort(P,P+N,compareX);	
	cout<<"x CoordSorted"<<endl;
	for(int i=0; i<N;++i)
		cout<<"("<<P[i].x<<","<<P[i].y<<")\t";
	cout<<endl;
	return( closest_Utill(P,0,N-1));

}


int main()
{
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f \n", closest(P, n));
    return 0;


}//main