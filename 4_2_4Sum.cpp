#include<bits/stdc++.h>
using namespace std;

void findFourElements(int *arr, int n, int target){
    unordered_map<int,pair<int,int>> sum_map; //map to store sum of two consecutive elements in the array
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            sum_map[arr[i]+arr[j]] = {i,j}; //store sum of elements as well as their index
        }
    }
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            int sum = arr[i] + arr[j];
            if(sum_map.find(target-sum) != sum_map.end()){ //if required sum is found in the map
                pair<int,int> p = sum_map[target-sum];
                if(p.first != i && p.second != j && p.first != j && p.second != j){ //if the sum found in map is not the same as the other two elements
                    cout<<"Elements adding up to the target are "<<arr[i]<<", "<<arr[j]<<", "<<arr[p.first]<<", "<<arr[p.second];
                    return;
                }
            }
        }
    }
}

int main(){
    int arr[] = {2,5,3,6,4,1,3,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 20;
    findFourElements(arr,n,target);
}