//Max continuous number of 1s

#include<bits/stdc++.h>
using namespace std;

int getMaxNum1s(int *arr, int n){
    int max_size = 0;
    int temp_size = 0;
    int slow_ptr = 0; //slow ptr moves when we encounter a zero
    for(int i=0;i<n;++i){ //if we find a zero, we can get the number of 1s till that point by substracting curr index from slow ptr
        if(arr[i] == 0){
            temp_size = i - slow_ptr;
            max_size = max(max_size,temp_size); //check if the temp size of 1s is greater than max size
            slow_ptr = i+1;
        }else if(i==n-1){ //when curr ptr reaches end of arr with no terminating 0
            temp_size = i - slow_ptr + 1; //since there is no terminating 0
            max_size = max(max_size,temp_size);
        }
    }
    return max_size;
}

int main(){
    int arr[] = {1,1,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //int arr[] = {1,1,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getMaxNum1s(arr,n)<<endl;
}