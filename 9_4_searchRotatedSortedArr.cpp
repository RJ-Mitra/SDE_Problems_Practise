//Given a rotated sorted array, find if the key exists in the array in O(logn) time

//E.g. 5,6,7,8,1,2,3
//Array is rotated

//Optimized approach
//We find the mid. We check if left most element is lower than mid. If true, this means the left half of the array is sorted.
//Otherwise the right half is sorted.
//We check if the element is present in the sorted half or unsorted half and recursively do a binary search for that half till we find the element
#include<bits/stdc++.h>
using namespace std;


int findKeyBinarySearch(vector<int>& arr, int left, int right, int key){
    if(left>right) return -1; //if iterators cross each other, the element is not found
    int mid = left + (right-left)/2;
    if(arr[mid] == key){ //base case for recursion
        cout<<"Key "<<key<<" found at position "<<mid<<".";
        return mid;
    }
    if(arr[left]<=arr[mid]){ //if left half is sorted
        if(key>=arr[left] && key<=arr[mid]){ //check for the element in sorted left half
            return findKeyBinarySearch(arr,left,mid-1,key);
        }else{ //else in unsorted right half
            return findKeyBinarySearch(arr,mid+1,right,key);
        }
    }else{ //right half is sorted
        if(key>=arr[mid] && key<=arr[right]){ //check in sorted right half
            return findKeyBinarySearch(arr,mid+1,right,key);
        }else{
            return findKeyBinarySearch(arr,left,mid-1,key); // or in unsorted left half
        }
    }
}

int main(){
    vector<int> arr = {5,6,7,8,1,2,3};
    int key = 7;
    int res = findKeyBinarySearch(arr,0,arr.size()-1,key);
    if(res == -1) cout<<"Key "+key+" is not present in the array.";
}