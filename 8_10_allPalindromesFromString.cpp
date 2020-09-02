//All possible palindromes of given string

//Given a string, print all possible palindromes that is present in that string

#include<bits/stdc++.h>
using namespace std;

//function to check if the string is a palindrome
bool isPalindrome(string str, int start, int end){
    while(start<end){
        if(str[start]!=str[end]) return false;
        start++;
        end--;
    }
    return true;
}

//recursive function to go through all possible combinations of string and print the palindromes
void getAllPalindromes(vector<vector<string>>& result, vector<string>& curr_part, string str, int start, int n){
    if(start>=n){ //if the length of the string is reached or exceeded, we push the current part to the result
        result.push_back(curr_part);
        return;
    }
    for(int i=start;i<n;++i){ //for each combination from current start to end of string
        if(isPalindrome(str,start,i)){ //if the string is a palindrome
            curr_part.push_back(str.substr(start,i-start+1)); //we add the string to the current part result
            getAllPalindromes(result,curr_part,str,i+1,n); //we recurse to find more palindromes from i+1 to end of string
            curr_part.pop_back(); //backtrack
        }
    }
}

int main(){
    string str = "nitin";
    int n = str.size();
    vector<vector<string>> result;
    vector<string> curr_part;
    getAllPalindromes(result,curr_part,str,0,n);
    //print all results
    for(int i=0;i<result.size();++i){
        for(int j=0;j<result[i].size();++j){
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
    }

}