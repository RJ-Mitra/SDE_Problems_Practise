//Find all set bits in a number in O(logn) time

//Approach: Brian Kernighan's Algorithm - For number n, n-1 flips all the digits from the rightmost set bit. E.g. 101 (5) & 100(4). (Rightmost set bit is flipped)
//                                        Each time we do n&(n-1), the rightmost set bit is flipped with each iteration
//                                        if we continue doing this till num = 0 and keep count of steps, we get number of set bits

//26 = 11010
//25 = 11001
//26&25 = 11000

#include<bits/stdc++.h>
using namespace std;

int findSetBits(int n){
    int count = 0;
    while(n>0){
        n=n&(n-1);
        count++;
    }
    return count;
}

int main(){
    int n = 7;
    cout<<findSetBits(n);
}