//Find element that appears once in sorted array, rest appears twice

//Given a sorted list of elements, find the element that appears only once

//Approach - Binary Search (Divide and Conquer)

//In the arr, all elements are in pairs except one. Therefore every element at even place will be equal to its prevent element until
//the single element occurs. Once the single element comes, the next pairs will have 1st element in even place and 2nd element in odd's place
//We perform binary searches to find where this change occurs. The single element will exist at that place.

#include<bits/stdc++.h>
using namespace std;

void findSingleElement(vector<int>& arr, int low, int high){
    if(low>high) return; //if exceeds limit, return
    if(low == high) { //if low == high, binary search has reached the result. We print it
        cout<<arr[low];
        return;
    }
    int mid = low + (high-low)/2; //we find the mid of all elements in the arr range
    if(mid%2 == 0){ //if the mid is even, then there are odd number of elements in the arr (E.g. 5,5,6,6,7) [0 based indexing]. Mid is 2. No. of elems is 5.
        if(arr[mid] == arr[mid+1]){ //since in pairs (say, 1st elm and 2nd elm are pairs) we have the find if mid and mid+1 are a pair
            findSingleElement(arr,mid+2,high); //if they are a pair, the single element will be to the right. We search in right half, starting with a new pair (mid + 2), since mid+1 is still 2nd of the old pair
        }else{
            findSingleElement(arr,low,mid); //otherwise single element in in left part, we search left half
        }
    }else{ //if mid is odd, there are even number of elements in the arr
        if(arr[mid] == arr[mid-1]){ //same as above
            findSingleElement(arr,mid+1,high);
        }else{
            findSingleElement(arr,low,mid-1);
        }
    }
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,4,4,5,6,6,7,7};
    findSingleElement(arr,0,arr.size());
}