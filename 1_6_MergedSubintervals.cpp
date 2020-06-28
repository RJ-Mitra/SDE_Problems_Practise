#include<bits/stdc++.h>
using namespace std;

//Given an array of subintervals, merge the intervals if they overlap
//E.g. {{1,2},{2,4}} -> {1,4}


//Approach 1 -> Using stack. Time -> O(nLogn) [because of sort],  Space -> O(n) [because of stack]
struct Interval{
    int begin;
    int end;
    Interval(int begin, int end){
        this->begin = begin;
        this->end = end;
    }
};

bool compareIntervals(Interval a, Interval b){
    return a.begin < b.begin;
}

void mergeIntervals_stackApproach(Interval arr[], int n){
    if(n<=0) return;
    sort(arr,arr+n,compareIntervals); //sorted so that the sub-array with the earliest start time always ends up as top
    stack<Interval> s;
    s.push(arr[0]); //sub-array with least start time is pushed to stack
    for(int i=1;i<n;++i){
        Interval top = s.top();
        if(top.end<arr[i].begin){ //no overlap between two subarrays
            s.push(arr[i]);
        }else if(top.end<arr[i].end){ //if the end time of i is greater than top and they overlap
            top.end = arr[i].end; //the greatest endtime of the two is taken as the end time for top
            s.pop(); //old top is popped from the stack
            s.push(top); //new top is pushed back
        }
    }
    while(!s.empty()){
        Interval top = s.top();
        cout<<"["<<top.begin<<","<<top.end<<"]\n";
        s.pop();
    }
}


//Alternate approach. Time -> O(nLogn), Space ->O(1)

void mergeIntervals(Interval arr[], int n){
    if(n<=0) return;
    sort(arr,arr+n,compareIntervals); //when sorted in ascending, all start times will be in order, making it easier to compare end time of one element with the start time of the next and determine if they overlap
    int index = 0;
    for(int i=1;i<n;++i){
        if(arr[index].end >= arr[i].begin){ //If the two intervals are overlapping
            arr[index].begin = min(arr[index].begin, arr[i].begin); //set the least start times among them as start
            arr[index].end = max(arr[index].end, arr[i].end); //set the max among their end times as the end time.
        }else{
            arr[index] = arr[i]; //if there is no overlap, the we move on to compare the next two subarrays
            ++i; //we increment i in addition to for loop incrementation to compare new index with its next element in next loop
        }
    } //Merged intervals are stored back in the original array. index acts as the counter for the number of merged indexes
    cout<<"\n The Merged Intervals are: ";  
    for(int i=0;i<=index;i++)  
        cout<<"["<<arr[i].begin<<","<< arr[i].end<<"]\n";
}


int main() 
{ 
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    mergeIntervals(arr, n);
}