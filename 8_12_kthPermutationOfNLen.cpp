//Kth permutation of a given range n

//Given a number n, generate a number from 1 to n and
//find the Kth permutation of that number

//Example:
//  Given n = 3, k = 2.
//  Number is 123. 3! permutations are possible -> 123,132,213,231,312,321.
//We need to find the kth permutation, i.e. 132

/*
Approach -
We can divide the permutations into blocks (1 based indexing)
digits ->    [1,2,3]
factorial -> [1,1,2]

Ans: _ _ _ (since n = 3)

        123
        132     Block 1

        213
        231     Block 2

        312
        321     Block 3
Each block will be of size (n-1)!
We can find the block of our required digit can be done by the formula: k/(n-1)!
But we need to do boundary check of (k%(n-1)!==0). If this is true, we decrement index by 1.
{Boundary check: If k is (2/(3-1)!) i.e 1, it is at boundary and might point us to block 1 instead of block 0. Hence we do boundary check to prevent this.}
In this scenario, index =  2/(3-1)! = 1. But 2%(3-1)! == 0, hence we decrement index to 0.
Therefore, out digit will be in block 0.
Since all elements in block 0 start with 1, out digit will be 1 or digits[0] -> 1

Ans: 1 _ _

We determined the element we need is in block 0, hence we can skip the other blocks by updating the k value.
k -> k - number of blocks to be skipped * number of elements in each block
k -> k - (n-1)! * index. Hence,
k = k-(n-1)!*index [index -> no. of blocks]
We update K value.
We remove this digit from digit arr since no elements can repeat. We decrease n by 1.
We continue this process for the next digit.


*/

#include<bits/stdc++.h>
using namespace std;

void solvePermutationUtil(string& answer, int n, int k, vector<int>& elements, vector<int>& factorial){
    if(n==1){ //if only 1 digit is left, we put that digit into the final place and return
        answer+=to_string(elements.back());
        return;
    }
    int index = k/factorial[n-1]; //we find the index of the digit by using the formula: k/(n-1)!;
    if(k%factorial[n-1]==0) index--; //for boundary case (elements at block boundaries need to be checked)
    answer+=to_string(elements[index]); //we add the digit to the answer
    elements.erase(elements.begin()+index); //we remove the digit from the main array
    k=k-factorial[n-1]*index; //we set the new k value by substracting index*(n-1)! from k
    solvePermutationUtil(answer,n-1,k,elements,factorial); //we recurse to find the next digit
}

void solvePermutation(int n, int k){
    string answer = "";
    vector<int> elements;
    vector<int> factorial;
    for(int i=1;i<=n;++i){ //stores all elements of the n digits
        elements.push_back(i);
    }
    factorial.push_back(1);
    int f = 1;
    for(int i=1;i<n;++i){ //stores factorial till n
        f*=i;
        factorial.push_back(f);
    }
    solvePermutationUtil(answer,n,k,elements,factorial);
    cout<<"Answer: "<<k<<"th permutation of "<<n<<" digits is: "<<answer<<endl;
}

int main(){
    int n = 3;
    int k = 2;
    solvePermutation(n,k);
}