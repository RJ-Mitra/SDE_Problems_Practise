//Combination Sum - I

//Given a list of elements and a sum value,
//find all unique combinations whose total value is
//equal to the given sum value

#include<bits/stdc++.h>
using namespace std;

//function to get the combination sets (elem vec, sum, i-> current element being utilised from elem vec, result vec, sum_set vec)
void combinationSum(vector<int>& elem, int sum, int i, vector<vector<int>>& result, vector<int>& sum_set){
    if(sum<0) return; //if the sum goes to negative, it means we added a bigger element in prev step. We cancel this solution tree and return
    if(sum==0){ //if sum is equal to 0, we found a solution.
        result.push_back(sum_set); //we append this solution set to the result vector
        return;
    }
    while(i<elem.size() && sum>=0){ //we loop through all elements of elem (i being current) till sum is equal to or greater than 0
        sum_set.push_back(elem[i]); //we push current element of elem into the possible sum set
        combinationSum(elem,sum-elem[i],i,result,sum_set); //we recursively check if a solution is possible (we decrease sum value by the current element size each time)
        i++; //we increase i to move to the next element in elem to try in set (this allows us to use each element multiple times)
        sum_set.pop_back(); //backtracking by removing the last added element
    }
}

//util function to standardize the input (sort and remove duplicates)
vector<vector<int>> getCombinations(vector<int>& elem, int sum){
    sort(elem.begin(),elem.end()); //sort the elements by ascending order
    elem.erase(unique(elem.begin(),elem.end()), elem.end()); //remove duplicates
    vector<vector<int>> result; //result vec to store all sets of values
    vector<int> sum_set; //sum_set containing all elements adding up to the given sum
    combinationSum(elem,sum,0,result,sum_set);
    return result;
}

int main(){
    vector<int> elem = {2,2,4,6,8};
    int sum = 8;
    vector<vector<int>> result = getCombinations(elem,sum);

    //print the sets
    for(int i=0;i<result.size();++i){
        if(result[i].size()>0){
            for(int j=0;j<result[i].size();++j){
                cout<<result[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}