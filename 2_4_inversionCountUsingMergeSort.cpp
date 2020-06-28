//Inversions in an array
/*
An array is said to have an inversion if a[i]>a[j] && i<j
E.g. 
{5,1,6,9} -> 1 inversion (5,1)
{2,3,5,6} -> no inversions
{ 1, 20, 6, 4, 5 } -> 5 inversions (20,6),(20,4),(20,5),(6,4),(6,5)
*/

#include <bits/stdc++.h>
using namespace std;

int merge(int *arr, int left, int mid, int right){
    int inverse_count = 0;
    int i,j,k;
    int nl = mid-left+1;
    int nr = right-mid;
    int leftArr[nl], rightArr[nr];
    for(i=0;i<nl;++i){
        leftArr[i] = arr[left+i];
    }
    for(j=0;j<nr;++j){
        rightArr[j] = arr[mid+1+j];
    }
    i=0, j=0, k=left;
    while(i<nl && j<nr){
        if(leftArr[i]>rightArr[j]){
            inverse_count+=(nl-i); //if left[i]>right[j], that means all elements to right of i are greater than right[j], hence [max elements in left - i] or [nl-i] inversions
            arr[k++] = rightArr[j++];
        }
        else{
            arr[k++] = leftArr[i++];
        }
    }
    while(i<nl){
        arr[k++] = leftArr[i++];
    }
    while(j<nr){
        arr[k++] = rightArr[j++];
    }
    return inverse_count;
}

int mergeSort(int *arr, int left, int right){
    int inverse_count = 0;
    if(right>left){
        int mid = left+(right-left)/2;
        inverse_count+=mergeSort(arr,left,mid); //get inversion count from each recursion
        inverse_count+=mergeSort(arr,mid+1,right);
        inverse_count+=merge(arr,left,mid,right);
    }
    return inverse_count;
}

int main() {
// 	int arr[] = {4,2,9,1,5,2,6,0};
    int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;++i) cout<<arr[i]<<" ";
	cout<<endl;
	int inverse_count = mergeSort(arr,0,n-1);
	for(int i=0;i<n;++i) cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"inverse_count = "<<inverse_count; //14 & 5
}
