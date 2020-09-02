//Minimum number of stations required for given train time tables

//Given a list of train arrival and departure times, find the
//minimum number of stations needed to cater to all trains

//Approach: Greedy
//Sort the arrival and departure times seperately.
//Using merge sort operation, compare arrival and departure times
//if an arrival time is less than a dep time, it means a train arrives
//before a deperature, so we need more platforms and vice-versa. So we add a platform
//The max number of platforms required at peak is the answer

#include<bits/stdc++.h>
using namespace std;

int getMinNumPlatforms(int* arr, int* dep, int n){
    int curr_platforms = 0;
    int total_platforms = 0;
    int i=0,j=0;
    sort(arr,arr+n);
    sort(dep,dep+n);
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            curr_platforms++;
            i++;
        }else if(arr[i]>dep[j]){
            curr_platforms--;
            j++;
        }
        total_platforms = max(total_platforms,curr_platforms);
    }
    return total_platforms;
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of platforms required: ";
    cout<<getMinNumPlatforms(arr,dep,n)<<endl;
}