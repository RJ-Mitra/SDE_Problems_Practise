#include<bits/stdc++.h>
using namespace std;


//If a matrix has 0, set that entire row and column to zeroes

//Solution with no extra space - O(1). Time - O(n^2)

/*
Note: If we start from index 0 and everytime we find a =n index with value 0, if we set all of its rows and columns as 0,
it will criss-cross the matrix and we will eventually end up setting the entire matrix to 0.
In this approach, we need to check the 1st row 1st for any 0, and mark it accordingly. Then we check each column and
finally we check middle elements for 0s.
*/
void setZeroes(vector<vector<int>>& matrix) {
    //sizes
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    
    bool first_row_zero = false;
    bool first_col_zero = false;
    
    //first row check for 0s.
    for(int i=0;i<col_size;++i){
        if(matrix[0][i] == 0){
            first_row_zero = true;
            break;
        }
    }
    //Check if any of the columns has zeroes and set the 1st row of every column with 0 as 0.
    for(int i=0;i<row_size;++i){
        for(int j=0;j<col_size;++j){
            if(matrix[i][j] == 0)
                matrix[0][j] = 0; //entire column is 0
        }
    }
    // Checks the entire grid instead of 1st row
    for(int i=1;i<row_size;++i){
        bool contains_zero = false;
        for(int j=0;j<col_size;++j){
            if(matrix[i][j] == 0){
                contains_zero = true;
                break;
            }
        }
        //Sets the entire rows and columns as 0 for each 0 value encountered
        for(int j=0;j<col_size;++j){
            if(contains_zero || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    //Finally, fill 1st row with zeroes if first_row_zero is true
    if(first_row_zero){
        for(int i=0;i<col_size;++i) matrix[0][i]=0;
    }
}

void print(vector<vector<int>>& vec){
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[0].size();++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    vector<vector<int>> vec = {{1,1,1},{1,0,1},{1,1,1}};
    print(vec);
    setZeroes(vec);
    print(vec);
}


//Alternate approach with more space

void setZeroes_morespace(vector<vector<int>>& matrix) {
    //sizes
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    
    vector<bool> row_vec(row_size);
    vector<bool> col_vec(col_size);

    for(int row=0;row<row_size;row++){
        for(int col=0;col<col_size;col++){
            if(matrix[row][col] == 0){
                row_vec[row] = true;
                col_vec[col] = true;
            }
        }
    }

    for(int row=0;row<row_size;row++){
        for(int col=0;col<col_size;col++){
            if(row_vec[row] || col_vec[col]){
                matrix[row][col] = 0;
            }
        }
    }
}