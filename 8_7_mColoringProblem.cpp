//m coloring problem of undirected graph

//Given an adjacency matrix for an undirected graph, find
//the minimum number of colors that is required to color all
//the graphs such that no adjacent vertices have the same color
//(m coloring optimization problem)

//Alternative: Given adjacency matrix and number of colors,
//find if the graph can be fully colored with no adjacent vertices
//having the same color
//(m coloring decision problem)

#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& adj_matrix, vector<int>& color){
    int N = adj_matrix.size();
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            if(adj_matrix[i][j] && color[i] == color[j])
                return false;
        }
    }
    return true;
}
//m -> no. of colors, i-> current vertex
bool graphColoring(vector<vector<int>>& adj_matrix, int m, int i, vector<int>& color){
    int n = adj_matrix.size();
    if(i==n){ //if current vertex is the last vertex, we have covered the graph
        if(isSafe(adj_matrix,color)) return true; //if the graph is safe (no neighbouring vertices having same color)
        return false;//if not safe
    }
    for(int j=1;j<=m;++j){ //iterate through all posibile colors and try inserting them
        color[i] = j;
        if(graphColoring(adj_matrix,m,i+1,color)) return true; //if color can be inserted, return true
        color[i] = 0; //backtrack
    }
    return false;
}

int main(){
    vector<vector<int>> adj_matrix = {{0,1,1,1},
                                      {1,0,1,0},
                                      {1,1,0,1},
                                      {1,0,1,0}};
    int n = adj_matrix.size(); //4x4 matrix means there are 4 vertices                                     
    int m = 3; //Number of colors
    vector<int> color(n,0); //array to store colors of each vertex
    if(!graphColoring(adj_matrix,m,0,color)) cout<<"No solutions exist.";
    else{
        cout<<"Graph can be colored by "<<m<<" colors.\nSolution:";
        for(int i:color) cout<<i<<" ";
    }
}