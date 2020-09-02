/*
Given an array of n, find the length of the largest sequence whose sum is equal to 0
*/

//Naive approach: Find all subsequences using two for loops (O(n*2) solution)

//Optimized approach -> Use a hash set to store all sum values. If a sum value is repeating,
//it means there is a subsequence whose value is equal to 0.
//E.g.  element:    4   -1  -3  2   -1  1
//      sum:        4    3   0  2   1   2
//                              ^       ^   The two sums are same, meaning there is a 0 sum between those two points. Len = 5 - 3 = 2

#include<bits/stdc++.h>
using namespace std;

int getLongestSeqSum0(int *arr, int n){
    int max_len = 0, sum = 0;
    unordered_map<int,int> sum_map;
    for(int i=0;i<n;++i){
        sum+=arr[i];
        if(arr[i] == 0 && max_len == 0){ //A sigle 0 will also qualify as a sequence with len 1
            max_len = 1;
        }
        if(sum == 0) max_len=i+1; //sum of all elements from 0 till i equals 0, hence length= i+1 (0 based indexing)
        if(sum_map.find(sum) != sum_map.end()){
            max_len = max(max_len, i - sum_map[sum]); //if sum is found, we know there is a 0 sum seq in the middle. We find the len of that seq
        }else{
            sum_map[sum] = i; //if sum is not seen before, we insert it into the map
        }
    }
    return max_len;
}

int main(){
    int arr[] = {-4, 1, 3, 2, 6, -7, 1, 5, 1, -3};
    //sum        -4 -3  0  2  8   1  2  7  8   5
    // int arr[] = {15,-2,2,-8,1,7,10,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getLongestSeqSum0(arr,n)<<endl;
}




//ALSO:
//Largest sequence with sum value k

//Same as zero sum, except we check in map for (sum - k)



/*
Given an array of n, find the length of the largest sequence whose sum is equal to k
*/

//Naive approach: Find all subsequences using two for loops (O(n*2) solution)

//Optimized approach -> Use a hash set to store all sum values. If a sum value is repeating,
//it means there is a subsequence whose value is equal to k.
//E.g.  element:    4   -1  -3  2   -1  1
//      sum:        4    3   0  2   1   2
//                              ^       ^   The two sums are same, meaning there is a k sum between those two points

// #include<bits/stdc++.h>
// using namespace std;

// int getLongestSeqSumK(int *arr, int n, int k){
//     int max_len = 0, sum = 0;
//     unordered_map<int,int> sum_map;
//     for(int i=0;i<n;++i){
//         sum+=arr[i];
//         if(arr[i] == k && max_len == 0){ //A single k will also qualify as a sequence with len 1
//             max_len = 1;
//         }
//         if(sum == k) max_len=i+1; //sum of all elements from 0 till i equals k, hence length= i+1 (0 based indexing)
//         if(sum_map.find(sum-k) != sum_map.end()){ //we search for (sum-k) in the map
//             // cout<<"From: "<<sum_map[sum-k]+1<<" To: "<<i<<endl;
//             max_len = max(max_len, i - sum_map[sum-k]); //if sum is found, we know there is a k sum seq in the middle. We find the len of that seq
//         }else{
//             sum_map[sum] = i; //if sum is not seen before, we insert it into the map
//         }
//     }
//     return max_len;
// }

// int main(){
//     int arr[] = {-4, 1, 3, 2, 6, -7, 1, 5, 1, -3};
//     //sum        -4 -3  0  2  8   1  2  7  8   5    //in arr[7], we see sum is 7. 7-6->. 1 is found in index arr[5]. Therefore len is 7-5 = 2
//     // int arr[] = {15,-2,2,-8,1,7,10,23};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k = 6;
//     cout<<getLongestSeqSumK(arr,n,k)<<endl;
// }