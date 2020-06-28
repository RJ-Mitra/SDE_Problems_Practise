//Given an array, find the sum of two elements in the array that is equal to a given target k.
//E.g. Arr-> 2,4,6,7,10,11; k->9. Ans: 0,3 (since 2+7 = 9)

#include<bits/stdc++.h>
using namespace std;


//unoptimized solution with more time taken, less space

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result(2,-1);
    vector<int>::iterator it;
    for(int i=0;i<nums.size();++i){
        it = find(nums.begin()+i+1,nums.end(),target-nums[i]);
        if(it!=nums.end()){
            result[0] = i;
            result[1] = it-nums.begin();
            return result;
        }
    }
    return result;
}


//With map. Faster than 95%, but more space
//Fastest

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result(2,-1);
    unordered_map<int,int> seen;
    for(int i=0;i<nums.size();++i){
        if(seen.find(target-nums[i])==seen.end()){
            seen.insert(make_pair(nums[i],i));
        }else{
            result[0] = i;
            result[1] = seen.find(target-nums[i])->second;
            return result;
        }
    }
    return result;
}


//Two pointer method
//Sorts the array, then moves inward from both ends
//DOES NOT RETURN ORIGINAL INDEXES BECAUSE OF SORTING

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        int temp = 0,j;
        //insertion sort (use inbuild sort for better performance)
        for(int i=1;i<nums.size();++i){
            j=i-1;
            temp = nums[i];
            while(j>=0 && nums[j]>temp){
                nums[j+1] = nums[j];
                --j;
            }
            nums[j+1] = temp; 
        }
        // sort(nums.begin(),nums.end());
        
        int begin = 0;
        int end = nums.size()-1;
        while(begin<end){
            if(nums[begin]+nums[end] == target){
                result[0] = begin;
                result[1] = end;
                return result;
            }
            if(nums[begin]+nums[end]<target){
                begin++;
            }else{
                end--;
            }
        }
        return result;
    }