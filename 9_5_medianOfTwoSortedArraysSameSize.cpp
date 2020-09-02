//Given two sorted arrays of same size, find the median of the arrays

//O(n) time, O(n) space -> Merge the two arrays into a 3rd array and print the median of that array
//O(logn) time -> Divide and Conquer using Binary search

#include<bits/stdc++.h>
using namespace std;

//find median of arr of size n
int median(int* arr, int n){
    if(n%2==0){
        return (arr[n/2]+arr[n/2-1])/2;
    }
    return (arr[n/2]);
}

int findMedian(int* arr1, int* arr2, int n){
    if(n<=0) return -1; //if arr has no elements, we return -1
    if(n==1) return (arr1[0]+arr2[0])/2; //if there are only 1 element in each arr, we return their avg as median
    if(n==2) return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2; //if each arr has 2 elements, out of 4 places, 1st will have min(arr1[0],arr2[0]) and last will have max(arr1[1],arr2[1]). Hence median elements will be the remaining, i.e. max(arr1[0],arr2[0]) and min(arr1[0],arr2[0])
    int m1 = median(arr1,n);
    int m2 = median(arr2,n);
    if(m1==m2) return m2;
    if(m1<m2){
        if(n%2==0) return findMedian(arr1+(n/2-1), arr2, n-n/2+1);
        return findMedian(arr1+n/2, arr2, n-n/2);
    }else{ //if m1>m2
        if(n%2==0) return findMedian(arr2+(n/2-1), arr1, n-n/2+1);
        return findMedian(arr2+n/2, arr1, n-n/2);
    }
}

int main(){
    int arr1[] = {2,5,7,9};
    int arr2[] = {1,3,8,11};
    // int arr1[] = {1,2,3,6};
    // int arr2[] = {4,6,8,10};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    // Both arrays are of same size
    cout<<findMedian(arr1,arr2,n);
}