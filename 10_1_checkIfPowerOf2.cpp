//Bits - check if a number is power of 2 or not in O(1)

//Approach - If a number is a power of 2, it's binary format will have a 1 at the beginning followed by all zeros
//          We can count the number of set bits. If the number of set bits is exactly equal to 1, it is a power of 2.
//          Also, if we substract 1 from the number, all bits get reversed. E.g. 8 (1000) - 1 (1) = 7 (0111).
//          If we take AND of both, we get 0 (1000 & 0111 = 0000). If we get zero, the number is a power of 2.
//          We and it with n and return the value as bool

//NOTE: Subtracting 1 from a decimal number flips all the bits after the rightmost set bit
/*
Example:
10 in binary is 00001010  ~ All bits from right most set bit are flipped below
9 in binary is 00001001
8 in binary is 00001000
7 in binary is 00000111

So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit. 
If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkIfPowerOfTwo(int n){
    if(n<2) return false;
    return n&&(!(n&(n-1)));
}

int main(){
    int n = 100;
    bool res = checkIfPowerOfTwo(n);
    if(res) cout<<"Number "<<n<<" is a power of 2";
    else cout<<"Number "<<n<<" is not a power of 2";
}