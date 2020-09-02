//Permutation of strings

//Given a string, find and print all possible combinations of the string

//Approach - Backtracking
//Swap each element with the 1st element and keeping the 1st element fixed,
//again recurse and swap elements in the next layer till the left and right elements are the same

/*
Example: s -> swap | swap(left with next to left)
                            ABC
        s(A,A)             s(A,B)              s(A,C)         
        A|BC                B|AC                C|BA
  s(B,B)   s(B,C)     s(A,A)   s(A,C)      s(B,B)   s(B,A)
    AB|C    AC|B        BA|C    BC|A        CB|A    C|AB
*/

#include<bits/stdc++.h>
using namespace std;

void printAllPermutations(string str, int l, int r){
    if(l==r){ //if l reaches r, we exit the recursion and print the answer
        cout<<str<<"\n";
    }
    else{
        for(int i=l;i<=r;++i){
            swap(str[l],str[i]); //swap left-most string for this iteration with curr i in loop
            printAllPermutations(str,l+1,r); //recurse with element next to l as new l (keeps l fixed)
            swap(str[l],str[i]); //backtrack
        }
    }
}


int main(){
    string str = "RUDRA";
    int n = str.length();
    printAllPermutations(str,0,n-1);
}