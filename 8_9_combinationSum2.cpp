//Combination Sum II

//Given a list of elements and a total sum, find the number of unique
//combinations equal to the sum that can be created from the element list
//NO ELEMENTS CAN BE USED MORE THAN THE NUMBER OF TIMES IT IS PRESENT IN THE list


#include<bits/stdc++.h>
using namespace std;

void combinationSum2(vector<int>& elements, int sum, int i, vector<vector<int>>& result, vector<int>& sum_set){
    if(sum<0) return;
    if(sum==0){
        result.push_back(sum_set);
        return;
    }
    while(i<elements.size() && sum>=0){
        sum_set.push_back(elements[i]);
        int j = i;
        ++i;
        combinationSum2(elements,sum-elements[j],i,result,sum_set);
        sum_set.pop_back();
    }
}

vector<vector<int>> getCombinationSum2(vector<int>& elements, int sum){
    sort(elements.begin(),elements.end()); //sorting elements in descending order to get gradualy increasing sum in summation process
    vector<vector<int>> result;
    vector<int> sum_set;
    combinationSum2(elements,sum,0,result,sum_set);
    //Removing duplicates
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    return result;
}

int main(){
    vector<int> elements = {10,1,2,7,6,1,5};
    int sum = 8;
    vector<vector<int>> result = getCombinationSum2(elements,sum);
    
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