//Trapping rainwater

//Given an array of integers representing vertical blocks, find how much water can be trapped in places between the blocks

//Optimised sol: O(n) time, O(1) space

/*
Solution: We take two variables to store highest values of left and right seen till now.
If we see a new higher val, we update its corresponding side highest value.
When we see that the val of one side is lower than the other, we move the lower side.
We check if the side has a height less than the max, since we cannot store any water on max value as it will spill.
If the curr val is lower than max val of that side, we store water in it equal to height diff between curr val and max height,
as we are sure that the other side has a higher value. Then we move the pointer ahead.
*/


#include<bits/stdc++.h>
using namespace std;

int findTrappedRainwater(int* arr, int n){
    int total = 0;
    int highest_left = 0, highest_right = 0;
    int left = 0; //left most element
    int right = n-1; //right most element
    while(left<right){ //while pointers do not meet
        if(arr[left]<arr[right]){ //if left is lower than right, then right has a higher value. We calculate water stored in left
            if(arr[left] >= highest_left) highest_left = arr[left]; //if left is higher than left_max, we update left_max and move on as water cannot be stored on max
            else total+= (highest_left - arr[left]); //else we calculate water stored = max - curr height
            left++; //we move the left pointer ahead
        }else{ //same with right in else condition
            if(arr[right]>= highest_right) highest_right = arr[right];
            else total+= (highest_right-arr[right]);
            right--;
        }
    }
    return total;
}


int main(){
    //int arr[] = {3,0,2,1,4};
    int arr[] = {7,1,4,0,2,8,6,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = findTrappedRainwater(arr,n);
    cout<<res<<endl;
}