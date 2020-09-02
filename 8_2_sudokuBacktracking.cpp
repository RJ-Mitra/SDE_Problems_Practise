//Sudoku solver

//Given a partially solved sudoku array,
//solve the sudoku puzzle

//Approach - Backtracking

#include<bits/stdc++.h>
using namespace std;

void printSudokuBoard(vector<vector<int>>& grid){
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool isSafe_col(vector<vector<int>>& grid, int col, int x){
    for(int row=0; row<grid[0].size(); row++){
        if(grid[row][col]==x) return false;
    }
    return true;
}

bool isSafe_row(vector<vector<int>>& grid, int row, int x){
    for(int col=0; col<grid.size(); col++){
        if(grid[row][col]==x) return false;
    }
    return true;
}

bool isSafe_grid(vector<vector<int>>& grid, int row, int col, int x){
    int first_row_in_grid = row - (row%3);
    int first_col_in_grid = col - (col%3);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(grid[i+first_row_in_grid][j+first_col_in_grid]==x) return false;
        }
    }
    return true;
}

bool isSafe(vector<vector<int>>& grid, int row, int col, int x){
    return (grid[row][col] == 0 && isSafe_row(grid,row,x) &&
            isSafe_col(grid,col,x) && isSafe_grid(grid,row,col,x));
}

bool findUnassignedPosition(vector<vector<int>>& grid, int& row, int& col){
    for(row=0;row<grid.size();row++){
        for(col=0;col<grid[0].size();col++){
            if(grid[row][col] == 0) return true;
        }
    }
    return false;
}

bool solveSudoku(vector<vector<int>>& grid){
    int row, col;
    if(!findUnassignedPosition(grid,row,col)) return true;

    for(int num=1;num<=9;num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col] = num;
            if(solveSudoku(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> sudokuBoard =  {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                                        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                                        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                                        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                                        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                                        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                                        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                                        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    
    if(!solveSudoku(sudokuBoard)) cout<<"No solution exists";
    else printSudokuBoard(sudokuBoard);
}