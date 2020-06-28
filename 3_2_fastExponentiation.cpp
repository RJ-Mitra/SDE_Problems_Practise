//Find power of any number in O(logn) time.
//Method: Fast exponentiation
//Change power to bit format E.g. 5->101. After each iteration, right shift each bit.
//Multiply the num to result if the current bit is 1./
//multiply num by itself in each iteration

#include<bits/stdc++.h>
using namespace std;

int fastExpo(int x, int n){
    if(n==0) return 1;
    int result = 1;
    while(n>0){
        if(n&1) result*=x;
        n=n>>1;
        x*=x;
    }
    return result;
}

int main(){
    int x = 2;
    int n = 5;
    cout<<fastExpo(x,n)<<endl;
}