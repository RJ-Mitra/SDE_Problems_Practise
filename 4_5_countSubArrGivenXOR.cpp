//Count of sub-arrays whose XOR of elements is equal to given number k

//Note: If the sum of a combination of numbers in a sequence is equal to each other,
//then the total XOR of the series will be equal to 0. E.g. 2,5,7 (2+5 = 7)
//5,7,1,3 -> (5+3 = 7+1) -> XOR = 0

#include<bits/stdc++.h>
using namespace std;


int getCountSubArrGivenXOR(vector<int>& arr, int k){
    int count = 0;
    int n = arr.size();
    vector<int> prefix_arr(n,0);
    unordered_map<int,int> xor_map; //map to store all prefixes with a particular XOR value and their count
    //Calculating prefix arr //E.g. 5,6,7,8,9 -> 5,3,4,12,5 (prefix[i] has all xor of 0...i vals). The prefix array has gradual XOR of all. If a prefix is repeating, it means we have an subarray with XOR 0 in between
    prefix_arr[0] = arr[0];
    for(int i=1;i<n;++i){
        prefix_arr[i] = prefix_arr[i-1]^arr[i];
    }
    for(int i=0;i<n;++i){
        int temp = k^prefix_arr[i]; //E.g. 5^5 = 0. //If temp exists in map, then there is another prefix with same XOR value
        count = count + (xor_map[temp]); // 1. xor_map[0] = 0 //i.e. subarray with XOR value k is ending at current index i. We add count of such elements
        if(prefix_arr[i] == k) count++; //5 == k, hence count = 1 //if we find a XOR value matching k, we increase count by 1. For direct matches
        xor_map[prefix_arr[i]]++; //xor_map[5] = 1 //we increment the current prefix value in the map
    }
    return count;
}


int main(){
    // vector<int> arr = {5,6,7,8,9};
    vector<int> arr = {4,2,2,6,4};
    int k = 5;
    cout<<getCountSubArrGivenXOR(arr,k)<<endl;
}