//Find duplicates in an array of positive integers
//0<=n<=arr_size
//const space, linear time

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {3,7,4,1,9,4,2,6,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;++i){
        if(arr[abs(arr[i])]<0) cout<<abs(arr[i])<<" is duplicate."<<endl; //if any element is negative, it is a duplicate
        else{
            arr[abs(arr[i])]*=-1; //Sets the element whose index is the same as the value of the current element to negative
        }
    }
    
}