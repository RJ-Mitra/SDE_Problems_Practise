//Subset sum 1

//Given a set of elements and a target, find 
//all the subsets whose sum equals the target

#include<bits/stdc++.h>
using namespace std;

//function to print all values of a subset
void printSubset(vector<int> subset, int n){
    for(int i=0;i<n;++i){
        cout<<subset[i]<<" ";
    }
    cout<<"\n";
}

//function to get all subsets adding up to target sum
void subset_sum(vector<int>& elements, vector<int>& subset, int subset_size, int sum, int iteration, int target){
    if(sum==target){ //if sum equals target, we found a valid subset.
        printSubset(subset,subset_size); //We print the subset elements
        subset_sum(elements,subset,subset_size-1,sum-elements[iteration],iteration+1,target); //we move forward with the next iteration
    }else{
        for(int i=iteration;i<elements.size();++i){ //we start from current iteration till last element in elements list
            subset[subset_size] = elements[i]; //we take each element and add it to the subset
            subset_sum(elements,subset,subset_size+1,sum+elements[i],i+1,target); //we recurse to check if the element added to the subset meets the target
        }
    }
}

void getAllSubsetsUtil(vector<int>& elements, int target){
    vector<int> subset(10); //subset vector to hold each subset of values
    subset_sum(elements,subset,0,0,0,target); //0 as subset index, sum value and iteration number
}

int main(){
    vector<int> elements = {10,7,5,18,12,20,15};
    int target = 35;
    getAllSubsetsUtil(elements,target);
}