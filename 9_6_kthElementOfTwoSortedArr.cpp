//Given two sorted arrays, find the kth element of that arrays

//Approach 1 -> merge operation - merge both arrays and return kth element of merged arrays
//Approach 2 -> merge operation - Keep track of elements while merging and return the element when the tracking variable equals k (no need to merge full arr)
//Approach 3 (Optimised) - Divide and conquer using binary search to find the kth element

//

#include<bits/stdc++.h>
using namespace std;

//We create a reduced sub-problem with halving of one array based on conditions
int getKthElement(int* arr1, int* arr2, int* end1, int* end2, int k){
    if(arr1==end1) return arr2[k]; //if arr1 has no elements and k still hasn't been found, we return kth element of arr2
    if(arr2==end2) return arr1[k]; //if arr2 has no elements, we return kth element of arr1
    int mid1 = (end1-arr1)/2;
    int mid2 = (end2-arr2)/2; //find mids of both arrays
    if(mid1+mid2<k){ //if sum of both mids is less than k, k should be in the 2nd half of one of the arrays
        if(arr1[mid1]>arr2[mid2]) return getKthElement(arr1, arr2+mid2+1, end1, end2, k-mid2-1); //if mid1 val > mid2 val, we search entire arr1 and 2nd half of arr2, k is updated to account for the decreased 2nd half of arr2
        return getKthElement(arr1+mid1+1, arr2, end1, end2, k-mid1-1); //if mid2>mid1 val, we search full arr2 and 2nd half of arr1, k is updated for decreased 2nd half of arr1
    }else{ //is sum of mids is greater than k,k should be in the left half of the arrays
        if(arr1[mid1]>arr2[mid2]) return getKthElement(arr1,arr2,arr1+mid1,end2,k); //if mid1>mid2 val, we search  1st half of arr1 and entire arr2
        return getKthElement(arr1,arr2,end1,arr2+mid2,k); //if mid2>mid1, we search 1st half of arr2 and entire arr1
    }
}

//Alternate

int findKthElement(int* arr1, int m, int* arr2, int n, int k){
    if(k>(m+n) || k<1) return -1; //if k is greater than combined size of both arrays, return -1
    if(m>n) return findKthElement(arr2,n,arr1,m,k); //We need the 1st array to be smaller than the 2nd. If it is reverse (m>n), we reverse it recursively
    if(m==0) return arr2[k-1]; //if m has no elements left and k is yet to be found, we return kth element of arr2 (k-1 due to 0 based indexing)
    if(k==1) return min(arr1[0],arr2[0]); //if k is the 1st element, we find minimum of the 1st elements of both sorted array
    int i=min(m,k/2); //Divide and conquer. We take either k/2 or m if k/2 is greater than the current array size
    int j=min(n,k/2);
    if(arr1[i-1]>arr2[j-1]) return findKthElement(arr1,m,arr2+j,n-j,k-j); //if arr val of i is greater than arr2 val of j, we search entire 1st arr and 2nd half of arr2
    return findKthElement(arr1+i,m-i,arr2,n,k-i); //else we in 2nd half of arr1
}

int main(){
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6,8};
    int k = 3;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<getKthElement(arr1,arr2,arr1+n1,arr2+n2,k-1)<<endl; //k-1 since 0 indexed, hence 3rd element will be the 2nd in array and so on
    cout<<findKthElement(arr1,n1,arr2,n2,k);
}