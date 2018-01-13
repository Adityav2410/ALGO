/* 
Rotate matrix
Given an image represented by an NxN matrix, where each pixel is in the image is 4 bytes, 
write a method to rotate the image by 90 degrees. Can you do thi inplace ?
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
    cout<<endl;
        
}

void rotateMatrixUsingTransposeStrategy(vector<vector<int>> matrix){
    int nRow = matrix.size();
    if( !nRow )
        return;
    int nCol = matrix[0].size();

    //transpore of matrix
    for(int i = 0; i < nRow; ++i)
    	for(int j = i+1; j < nCol; ++j){
    		int temp = matrix[i][j];
    		matrix[i][j] = matrix[j][i];
    		matrix[j][i] = temp;
    	}

    // Horizontal flip of matrix
    for(int i = 0; i < nRow; ++i)
    	for(int j = 0; j < nCol/2; ++j){
    		int temp = matrix[i][j];
    		matrix[i][j] = matrix[i][nCol-j-1];
    		matrix[i][nCol-j-1] = temp;

    	}
    cout<<"Rotated matrix with transpose strategy: "<<endl;
	print2dVector(matrix);
}


void rotateMatrixInLayers(vector<vector<int>> matrix){
    int nRow = matrix.size();
    if( !nRow )
        return;
    int nCol = matrix[0].size();

    // iterate through all the n/2 layers
    for(int i = 0; i < nRow/2; ++i){
    	//pick ith layer - reference is top layer
    	for(int j = i; j < nRow-1-i; ++j){
    		int temp = 	matrix[i][j];
    		matrix[i][j] 			= 	matrix[nRow-1-j][i];
    		matrix[nRow-1-j][i] 		= 	matrix[nRow-1-i][nRow-1-j];
    		matrix[nRow-1-i][nRow-1-j] 	= 	matrix[j][nRow-1-i];
    		matrix[j][nRow-1-i] 		= 	temp;
    	}	// in each layer, rotate each element one-by-one
    }	// rotate for ith layes
    print2dVector(matrix);
}


int main(){

	vector<vector<int>> matrix = {	{ 7,  9  , 13 , 21 , 17 },
									{ 3,  12 , 29 , 81 , 63 },
									{ 13, 87 , 05 , 19 , 8  },
									{ 65, 23 , 53 , 24 , 87 },
									{ 93, 60 , 35 , 43 , 29 },
								};

	cout<<"Original matrix: "<<endl;
	print2dVector(matrix);
	cout<<endl<<endl;

	int choice;
	cout<<"Enter strategy for rotation\n1.Transpose based strategy\n2.Layer-by-layer rotation"<<endl;
	cin>>choice;
	if( choice == 1 )
		rotateMatrixUsingTransposeStrategy(matrix);
	else
		rotateMatrixInLayers(matrix);
}

