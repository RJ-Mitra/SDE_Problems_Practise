/*
Given an array of length n, find the longest sequence of digits that are consecutive
E.g. arr[] = {1,5,8,2,9,3,4};
subsequences are: 1,2,3,4,5 and 8,9. Longest subsequence is 1,2,3,4,5. Length -> 5
*/

#include<bits/stdc++.h>
using namespace std;

//Naive approach: sort the array and check if preceding element+1 = next element. Take count of longest.
//O(nlogn) time (due to sort (logn) and 1 traversal(n)). Space- O(1)

//Optimizes approach - Use hash set to store all elements and find their lengths

int getLongestConsecutiveSubseqLen(int *arr, int n){
    unordered_set<int> s;
    int max_len = -1, curr_len = -1;
    for(int i=0;i<n;++i){
        s.insert(arr[i]); //inserting all elements in the set
    }
    for(int i=0;i<n;++i){
        if(s.find(arr[i]-1) == s.end()){ //if the prev element is not found in set, this is the first element of sequence
            int element = arr[i]; //1st element of sequence
            while(s.find(element)!=s.end()){ //if elements++ are in set, we find the last element in continious sequence
                element++;
            }
            curr_len = element - arr[i]; //len of sequence is largest element in seq - first element of sequence
        }
        max_len = max(max_len,curr_len); //max length
    }
    return max_len;
}

int main(){
    int arr[] = {15,1,5,12,9,2,11,4,13,8,3,10,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getLongestConsecutiveSubseqLen(arr,n)<<endl;
}