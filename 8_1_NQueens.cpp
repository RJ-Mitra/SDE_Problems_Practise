//N-queens problem

//Given a chessboard of size N, find the number of queens
//that can be placed on the board so that none of the queens
//are attacking each other

//Approach - Backtracking (Naive approach)

#include<bits/stdc++.h>
using namespace std;

#define N 4

//check is column to the left has no attacking queens
bool colLeft_safe(vector<vector<int>>& sol, int x, int y){
    while(y>=0){
        if(sol[x][y]!=0) return false;
        y--;
    }
    return true;
}

//check if leftUp diagonal has any attacking queens
bool leftUpDiagonal_safe(vector<vector<int>>& sol, int x, int y){
    while(x>=0 && y>=0){
        if(sol[x][y]!=0) return false;
        x--;
        y--;
    }
    return true;
}

//check if leftDown diagonal has any attacking queens
bool leftDownDiagonal_safe(vector<vector<int>>& sol, int x, int y){
    while(x<N && y>=0){
        if(sol[x][y]!=0) return false;
        x++;
        y--;
    }
    return true;
}

//check if current position is safe
bool isSafe(vector<vector<int>>& sol, int x, int y){
    return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==0 &&
            colLeft_safe(sol,x,y) && leftUpDiagonal_safe(sol,x,y) 
            && leftDownDiagonal_safe(sol,x,y));
}

//print the solition board
void printBoard(vector<vector<int>>& sol){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n\n";
}

//Print any solution
bool NQUtil(vector<vector<int>>& sol, int col){
    //base case
    if(col >= N) return true;

    for(int i=0;i<N;++i){
        if(isSafe(sol,i,col)){
            sol[i][col] = 1;
            if(NQUtil(sol,col+1)) return true;
            sol[i][col] = 0;
        }
    }
    return false;
}

//Print all solutions
bool NQUtil_allSolutions(vector<vector<int>>& sol, int col){
    if(col==N){
        printBoard(sol);
        return true;
    }
    bool res = false;
    for(int i=0;i<N;++i){
        if(isSafe(sol,i,col)){
            sol[i][col] = 1;
            res = NQUtil_allSolutions(sol,col+1) || res; //make the result true if any placement is possible
            sol[i][col] = 0;
        }
    }
    return res;
}

//To get any one solution
void solveNQ(){
    vector<vector<int>> sol(N,vector<int>(N,0));
    if(!NQUtil(sol,0)) cout<<"No solutions exist";
    else printBoard(sol);
}

//To get all possible solutions
void solveNQ_allSolutions(){
    vector<vector<int>>sol(N,vector<int>(N,0));
    if(!NQUtil_allSolutions(sol,0)) cout<<"No solutions exist";
    return;
}

int main(){
    solveNQ_allSolutions();
}

//Optimised solution

//Instead of checking if every position is safe, use properties of diagonals
/*
1. For each right diagonal, SUM of i and j is constant and unique
2. For each left diagonal, DIFF of i and j is constant and unique
i -> row, j -> col
*/

//global arrays: rd->right diagonal, ld->left diagonal, cl->col left
int rd[30] = {0};
int ld[30] = {0};
int cl[30] = {0};

//In order to see if pos is safe, we just need to check ld[i-col+N-1] !=1, rd[i+col] != 1,cl[i] != 1
bool solveNQUtil_optimized(vector<vector<int>>& sol, int col){
    if(col>=N) return true;
    for(int i=0;i<N;++i){
        if((ld[i-col+N-1])!= 1 && rd[i+col]!= 1 && cl[i]!=1){
            sol[i][col] = 1;
            ld[i-col+N-1] = rd[i+col] = cl[i] = 1;
            if(solveNQUtil_optimized(sol,col+1)) return true;
            sol[i][col] = 0;
            ld[i-col+N-1] = rd[i+col] = cl[i] = 0;
        }
        return false;
    }
}