/*
Zero Matrix
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

template <class T>
void print2dVector(vector<vector<T>> matrix){
	int nRow = matrix.size();
	if( !nRow )
		return;
	int nCol = matrix[0].size();
	for(int i = 0; i < nRow; ++i){
		for(int j = 0; j < nCol; ++j)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}
} // print2dVector


int main(){

	// input matrix
	vector<vector<int>> matrix = {	{ 7,  9  , 13 , 0 , 17 },
									{ 3,  0 , 29 , 81 , 63 },
									{ 13, 87 , 05 , 19 , 8  },
									{ 65, 23 , 0 , 24 , 87 },
									{ 93, 60 , 35 , 43 , 29 },
								};
	print2dVector(matrix);
	int nRow = matrix.size();
	int nCol = matrix[0].size();
	bool firstRowZero = false, firstColZero = false;

	for(int i = 0; i < nRow; ++i)
		for(int j = 0; j < nCol; ++j){
			if( (i&j) == 0 && matrix[i][j] == 0 ){
				firstRowZero = i==0 ? true : firstRowZero;
				firstColZero = j==0 ? true : firstColZero;
			}
			else if( matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	cout<<"\n\nMarked matrix: "<<endl;
	print2dVector(matrix);
	for(int i = 1; i < nRow; ++i)
		for(int j = 1; j < nCol; ++j){
			if( matrix[0][j] == 0 || matrix[i][0] == 0)
				matrix[i][j] = 0;
		}
	if( firstRowZero )	
		for(int j = 0; j < nCol; ++j)
			matrix[0][j] = 0;
	if( firstColZero )	
		for(int i = 0; i < nCol; ++i)
			matrix[i][0] = 0;

	cout<<"\n\nZeroed matrix: "<<endl;
	print2dVector(matrix);
}