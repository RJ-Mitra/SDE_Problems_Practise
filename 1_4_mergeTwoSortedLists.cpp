//Merged two sorted lists with no extra space. Space = O(1)
//Plan is to sort both arrays such that all elements in array 2 are greater than all elements in array 1

#include<bits/stdc++.h>
using namespace std;

void mergeSortedArr(int *arr1, int *arr2, int arr1_size, int arr2_size){
    for(int i=arr2_size-1;i>=0;--i){ //iterate over the 2nd array
        int j, last = arr1[arr1_size-1]; //take note of last element in arr1 as it will get replaced
        for(j=arr1_size-2;j>=0 && arr1[j]>arr2[i];--j){ //until element is arr2 is greater than arr1, starting with 2nd last element in arr1
            arr1[j+1] = arr1[j]; //keep shifting elements to the right by 1 place
        }
        //loop terminates when an element in arr1 is greater than the element of arr2
        if(j!=arr1_size-2 || last>arr2[i]){ //if j is not same as the initial j in the above loop, OR last element of arr1 is greater than the correspnding element in arr2
            arr1[j+1] = arr2[i]; //replace the element in arr1 which is greater than element in arr2 which is lower (lower element moves to arr1)
            arr2[i] = last; //we place the last element of arr1 in its place in 2nd arr (higher element moves to arr2)
        }
    }
}


int main(){
    int arr1[] = {1,2,2,5,7,8,12,27};
    int arr2[] = {-4,0,4,6,9,34};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    mergeSortedArr(arr1,arr2,arr1_size,arr2_size);
    
    cout << "After Merging nFirst Array: "; 
    for (int i=0; i<arr1_size; i++) 
        cout << arr1[i] << " ";
    cout<<endl;
    cout << "nSecond Array: "; 
    for (int i=0; i<arr2_size; i++) 
        cout << arr2[i] << " "; 
}