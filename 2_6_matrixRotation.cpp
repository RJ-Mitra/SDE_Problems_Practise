//Rotate Matrix

/*
Trick:

For left rotate, first swap the left and left most elements of each row of matrix inward, then transpose.
For right rotate, first transpose then swap left and right elements inward.
Transpose means to change row int column and column into row.
*/

#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &vec){
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[0].size();++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}


void swap(int& a, int&b){
    int temp = a;
    a = b;
    b = temp;
}

void rotateRight(vector<vector<int>> &matrix){
    vector<vector<int>> solMatrix(matrix.size(),vector<int>(matrix.size(),0));
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[0].size();++j){
            solMatrix[i][j] = matrix[j][i];
        }
    }
    for(int i=0;i<matrix.size();++i){
        for(int x=0,y=matrix.size()-1; x<y; x++,y--){
            swap(solMatrix[i][x], solMatrix[i][y]);
        }
    }
    
    matrix = solMatrix;
}


void rotateLeft(vector<vector<int>> &matrix){
    vector<vector<int>> solMatrix(matrix.size(),vector<int>(matrix.size(),0));
    for(int i=0;i<matrix.size();++i){
        for(int x=0,y=matrix.size()-1; x<y; x++,y--){
            swap(matrix[i][x], matrix[i][y]);
        }
    }
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[0].size();++j){
            solMatrix[i][j] = matrix[j][i];
        }
    }
    matrix = solMatrix;
}


int main() {
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};
    
    printMatrix(matrix);
    
    rotateLeft(matrix);
    
    printMatrix(matrix);          
}
