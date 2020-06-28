#include<bits/stdc++.h>
using namespace std;

//Kadane's algorithm to get the max sum of a sub-array in a given array
//E.g. Given array: {-2,2,5,4,-11,6}
//Max sum = 11 [2+5+4]
//E.g. Given array: {-2,2,5,4,-12,6,3,1,2}
//before -12, the max sum is 11. They max of 11+(-12) and -12 is -1
//Then max of -1+6 and 6 is 6, so we discard the previous curr sum and continue fresh from 6

int getMaxSum(int* arr, int n){
    int curr_max = 0;
    int total_max = 0;
    for(int i=0;i<n;++i){
        curr_max = max(curr_max+arr[i],arr[i]); //if arr[i] has a high -ve value, we choose the greater of the two
        total_max = max(curr_max,total_max); //if curr maximum is greater than the total max seen so far, current max is set to total max
    }
    return total_max;
}

int main(){
    int arr[] = {-2,2,5,4,-12,6,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum = getMaxSum(arr,n);
    cout<<"Max Sum = "<<maxSum;
}