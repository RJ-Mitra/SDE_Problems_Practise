//Find the median of a row-sorted matrix using binary search (where r and c are odd)

//Approach - Binary search
//The logic is: In an odd matrix, the number of elements greater than the median should be equal to the number of elements less than the median
//If we find a value for which the count of elements less than it matches the count of elements greater than it, we can mark it as the median

//NOTE: The upper_bound works with array but not with vector
//upper_bound returns the count of the number of elements greater than the value specified in the 3rd param
//1st and 2nd param are starting and ending iterators

#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int getMedian(int matrix[][MAX], int row, int col){
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i=0;i<row;++i){ //find max and minimum elements in the matrix
        if(matrix[i][0] < min) min = matrix[i][0];
        if(matrix[i][col-1] > max) max = matrix[i][col-1];
    }
    int desired = (row*col+1)/2; //find the mid count of elements in the odd matrix
    while(min<max){
        int mid = min+(max-min)/2; //We take the middle element value as the mid
        int places = 0;
        for(int i=0;i<row;++i){ //for each row, we find the number of elements which are greater than mid
            places+= upper_bound(matrix[i],matrix[i]+col,mid) - matrix[i]; //upper_bound returns the iterator of the 1st element greater than mid. We substract loc of 1st element from it to get the number of elements
        }
        if(places<desired) min = mid + 1; //if the no. of elements is less than desired, we take next element as mid (to the right)
        else max = mid; //else we move mid to the left
    }
    return min;
}

int main(){
    int matrix[][MAX] = {{1,3,5},
                         {2,6,9},
                         {3,6,9}};
    int row = sizeof(matrix)/sizeof(matrix[0]);
    int col = row;
    cout<<"Median of given matrix is: "<<getMedian(matrix,row,col)<<endl;
}