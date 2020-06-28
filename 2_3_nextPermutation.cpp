//Next permutation
/*
Given a number, find the next permutation of the number greater than the number.
If no greater permutation exists, return the lowest permutation of the number.

E.g. 123 -> 132
     12453 -> 12534
     321 -> 123
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}


void reverse(int *arr, int begin, int end){
    while(begin<end){
        swap(arr[begin++],arr[end--]);
    }
}


void printNextPermutation(int *arr, int n){
    int k = n-2;
    while(k>=0 && arr[k]>=arr[k+1]){
        --k;
    }
    if(k == -1){
        reverse(arr,0,n-1);
        for(int j=0; j<n; ++j) cout<<arr[j]<<" ";
        return;
    }
    for(int i=n-1; i>k; --i){
        if(arr[i]>arr[k]){
            swap(arr[k],arr[i]);
            break;
        }
    }
    reverse(arr,k+1,n-1);
    for(int i=0;i<n;++i) cout<<arr[i]<<" ";
}


int main(){
    //int arr[] = {3,2,1};
    //int arr[] = {1,2,3};
    int arr[] = {1,2,4,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNextPermutation(arr, n);
}