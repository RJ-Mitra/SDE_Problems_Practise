// Find 1/Nth root of an integer by using binary search

//Approach - Binary Search
//We take the mid value of the range and try to guess the correct root value using binary search
//instead of iterating through all the root values
//If the num is > 0 and < 1, it's root will fall between 0 and 1
//We assign min and max values and calculate the mid
//We calculate the power of the mid and match it with the number
//While the power of the mid minus the num is greater than or equal to epsilon (i.e. less precise)
//if the power of mid is greater than the num, we know our guess should be lesser. So we change max to mid/guess
//if pow of mid is less than num, we know guess should be more. We change min to guess and try again
//Eventually when we find the root, er print it


#include<bits/stdc++.h>
using namespace std;

void findNthRoot(double num, int n){
    double min,max,guess;
    double epsilon = 0.00000001; //setting the precision we need
    if(num>=0 && num<=1){ //if num is between 0 and 1
        min = num;
        max = 1;
    }else{
        min = 1;
        max = num;
    }
    guess = min + ((max-min)/2); //we take average of the range as our first guess
    while(abs(pow(guess,n)-num) >= epsilon){ //we loop until the diff between power of guess and number exceeds the required precision
        if(pow(guess,n)>num) max = guess; //if pow of guess > num, guess should be to the left. Hence we discard everything to right of max and set guess as new max
        else min = guess; //else root should be to the right of guess, hence we set guess min as guess and discard all to the left
        guess = min + ((max-min)/2); //we again take mid as guess
    }
    cout<<"Root "<<n<<" of "<<num<<" is ";
    cout<<fixed<<setprecision(16)<<guess;
}

int main(){
    double num = 5;
    int n = 2;
    findNthRoot(num,n);
}