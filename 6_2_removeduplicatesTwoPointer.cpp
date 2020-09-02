//Remove duplicates from sorted array (two_pointer method)

//Given a sorted array, remove the duplicates and return new size of array


//Approach: Use two pointer, one moves for each iteration while another moves when its 
//value is not matching with the fast ptr's. When we find a non-match, we store its
//value back in the original arr at slow ptr indeex and move the slow ptr by 1.
//For each non-match, we calculate the size

#include<bits/stdc++.h>
using namespace std;

int distinctArrSize(int *arr, int n){
    int new_size = 1;
    int slow_ptr = 0;
    for(int fast_pointer = 1; fast_pointer<n; fast_pointer++){
        if(arr[slow_ptr] != arr[fast_pointer]){
            arr[++slow_ptr] = arr[fast_pointer];
            new_size++;
        }
    }
    return new_size;
}

int main(){
    int arr[] = {1,2,3,4,4,5,6,6,6,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int new_sz = distinctArrSize(arr,n);
    for(int i=0;i<new_sz;++i) cout<<arr[i]<<" ";
    cout<<endl;
}