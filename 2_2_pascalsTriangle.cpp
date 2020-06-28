#include<bits/stdc++.h>
using namespace std;


/*
Pascal's triangle:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

if this is a matrix, [row-1][col-1] + [row-1][col] gives us the value of [row][col]
Note: Pascal's triangle matrix can give us the binomial coeff as well as ncr values

E.g. binomial coeff-> (a+b)^2 = 1a^2 + 2ab + 1b^2 -> coeff are: 1 2 1, same of row 2 of the triangle
ncr values: 3c2 -> 3rd row 2nd col -> [3][2] -> 3

*/

// space O(n^n), time - O(n^2)

void drawPascalTriangle(int n){
    int pascal_arr[n][n];
    for(int line=0;line<n;++line){ //number of lines
        for(int j=n-line;j>=0;--j) cout<<" "; //print spaces before each line to form equilateral triangle
        for(int i=0; i<=line; ++i){
            if(i==0 || i == line) pascal_arr[line][i] = 1; //the 1st and last elements of a line are always 1
            else{
                pascal_arr[line][i] = pascal_arr[line-1][i-1] + pascal_arr[line-1][i]; //value taken from array
            }
            cout<<pascal_arr[line][i]<<" ";
        }
        cout<<"\n";
    }
}


int main(){
    int n = 5;
    drawPascalTriangle(n);
}


//Alternate: const space O(1), time -> O(n^2)

void printPascal(int n) 
{ 
      
for (int line = 1; line <= n; line++) 
{ 
    int C = 1; // used to represent C(line, i) 
    for (int i = 1; i <= line; i++)  
    { 
          
        // The first value in a line is always 1 
        cout<< C<<" ";  
        C = C * (line - i) / i;  
    } 
    cout<<"\n"; 
} 
} 