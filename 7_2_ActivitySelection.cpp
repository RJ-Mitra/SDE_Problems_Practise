//Activity Selection
//(Similar to 7_1 N meetings in 1 room)

//Select the activities that can be held without overlapping
//Given activities are sorted by their endtimes

#include<bits/stdc++.h>
using namespace std;

void printMaxActivities(int *s, int *f, int n){
    int i = 0; //prev/1st activity
    cout<<"Activities are:"<<endl;
    cout<<i<<"\n";
    for(int j=1; j<n; ++j){//for all activities after 1st
        if(s[j]>=f[i]){ //if start time of next activity is greater than end time of prev activity
            cout<<j<<"\n"; //select the activity
            i = j; //set current activity as the prev 
        }
    }
}

int main(){ 
    int s[] = {1,3,0,5,8,5}; 
    int f[] = {2,4,6,7,9,9}; 
    int n = sizeof(s)/sizeof(s[0]); 
    printMaxActivities(s, f, n);
}