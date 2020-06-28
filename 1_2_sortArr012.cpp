//Sort an array of 0,1,2 inplace without any algorithms
//const space, linear time

//Alternate approach: Keep a count of 0,1 and 2s using one traversal of the array.
//In the second traversal, populate the array with the quantities of each element

#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void sort012(int *arr, int n){
    int low = 0; //low to mid for 0s
    int mid = 0; //mid area for 1s
    int hi = n-1; //mid to hi area for 2s
    while(mid<=hi){
        switch(arr[mid]){
            case 0:
                swap(arr[low],arr[mid]); //swaps and sents mid element (0) to the beginning of the array
                low++; //low is set to the next element
                mid++; //mid pointer moves to next element
                break;
            case 1:
                mid++; //if element at mid is 1, no need to move it
                break;
            case 2:
                swap(arr[mid],arr[hi]); //if element at mid is 2, sends it to the hi (end of array)
                hi--; //reduces the hi pointer
                break;
        }
    }
}

int main(){
    int arr[] = {1,2,1,0,2,2,0,1,0,0,1,0,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr,n);
    for(int i=0;i<n;++i) cout<<arr[i]<<" ";;
    cout<<endl;
    
}