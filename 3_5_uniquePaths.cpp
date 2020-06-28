//Given a matrix m x n, find the maximum number of unique paths than can be followed by an object
//at 0,0 to reach the target at m,n.


#include<bits/stdc++.h>
using namespace std;

//Backtracking solution:
//Throws TLE in some cases

// class Solution {
// public:
//     bool isSafe(vector<vector<int>>& visited, int x, int y, int m, int n){
//         if(x>=0 && x<m && y>=0 && y<n && visited[x][y]==0){
//             return true;
//         }
//         return false;
//     }
    
//     void findPaths(int x, int y, int m, int n, int& count, vector<vector<int>>& visited){
//         if(x==m-1 && y==n-1) count++;
//         else{
//             if(isSafe(visited,x,y,m,n)){
//                 visited[x][y] = 1;
//                 findPaths(x+1,y,m,n,count,visited);
//                 findPaths(x,y+1,m,n,count,visited);
//                 visited[x][y] = 0;
//             }
//         }
//     }
    
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> visited(m,vector<int>(n,0));
//         // sol[0][0] = 1;
//         int count = 0;
//         findPaths(0,0,m,n,count,visited);
//         return count;
//     }
// };

//DP approach
//O(mn) time & space

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1; //in case of a 1D array
        vector<vector<int>> dp(m,vector<int>(n,1)); //set all elements to 1 to auto calculate 1st row and 1st col elements as 1, since path to reach any cell in row 1 or col 1 is always 1
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};