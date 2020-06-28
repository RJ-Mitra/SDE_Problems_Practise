//Number of trailing zeros in factorial of a given number
//if num is 6, factorial = 720. Leading zero count -> 1

//We know that for each number, the count of leading zeroes is proportional to the number of 5s in that number.
//But numbers which are multiples of 5 (such as 25 and 125) have extra 5s in them, so we have to take them
//int account as well. So, for a number such as 127, leading zeros -> num/5 + num/25 + num/125

#include<bits/stdc++.h>
using namespace std;


int numTrailingZerosInFac(int num){
    int count = 0;
    for(int i=5;i<=num;i*=5){ //i increases by 5 after each iteration
        count+=num/i;
    }
    return count;
}

int main(){
    int num = 14;
    cout<<numTrailingZerosInFac(num)<<endl;
}