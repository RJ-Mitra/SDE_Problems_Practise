//Rat in a maze

//Given an array where 0 represents obstacles and 1 represents
//open paths, find the path out of the maze

//Note: Only right and down moves allowed

//Approach - Backtracking

#include<bits/stdc++.h>
using namespace std;

#define N 4

void printMaze(vector<vector<int>>& maze){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<maze[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

bool isSafe(vector<vector<int>>& maze, int row, int col, vector<vector<int>>& sol){
    return (row>=0 && row<N && col>=0 && col<N &&
            maze[row][col]!=0 && sol[row][col]!= 1);
}


bool mazeSolveUtil(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol){
    if(x==N-1 && y==N-1 && maze[x][y] == 1){
        sol[x][y] = 1;
        return true;
    }
    if(isSafe(maze,x,y,sol)){
        sol[x][y] = 1;
        if(mazeSolveUtil(maze,x+1,y,sol)) return true;
        if(mazeSolveUtil(maze,x,y+1,sol)) return true;
        sol[x][y] = 0;
    }
    return false;
}

void findMazePath(vector<vector<int>>& maze){
    vector<vector<int>> sol(N,vector<int>(N,0));
    if(mazeSolveUtil(maze,0,0,sol)) printMaze(sol);
    else cout<<"No path out of maze found";
}

int main(){
    vector<vector<int>> maze = {{ 1, 0, 0, 0 }, 
                                { 1, 1, 0, 1 }, 
                                { 0, 1, 0, 0 }, 
                                { 1, 1, 1, 1 }};
    findMazePath(maze);
}