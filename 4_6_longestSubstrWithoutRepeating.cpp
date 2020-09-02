#include<bits/stdc++.h>
using namespace std;

#define NUM_OF_CHARS 256
/*
Find length of longest substring without repeating elements.
Approach: Hashing
Time:(n+d) n-> length of str, d-> number of  chars in alphabet (256 here)
Space: O(d)
*/

int getLongestSubstrLen(string str){
    int n = str.size();
    int max_len = 0;
    int begin, end;
    vector<int> char_index(NUM_OF_CHARS,-1); //hash storing the last index of the char
    int start = 0;
    for(int j=0;j<n;++j){
        start = max(start, char_index[str[j]]+1); //start gets updated with each iteration
        max_len = max(max_len,j-start+1); //find max length of string without repeating
        char_index[str[j]] = j; //set new index of the repeating char to hash vector
    }
    return max_len;
}

int main(){
    // string str = "AJNOEUNAWUFCBAOF";
    string str = "geeksforgeeks";
    cout<<getLongestSubstrLen(str)<<endl;
}


//Alternate
//Using sliding window and hash-set

int getLongestSubstr(string str){
    int n = str.size();
    int max_len = 0;
    int begin = 0; //left pointer
    int end = 0; //right pointer
    unordered_set<char> s; //set to store all seen elements
    while(end<n){ //right pointer leads
        if(s.find(str[end]) == s.end()){ //if element is not in seen set
            s.insert(str[end]); //insert element into set
            int sz = s.size(); //find current size of set
            max_len = max(max_len, sz); //max set size is the max length of non-repeating elements
            end++; //move pointer to the next element
        }else{
            s.erase(str[begin]); //if element is found in set, it is repeating. Delete its earlier element from set
            begin++; //move left pointer to the right by 1, Don't increase the end pointer
        }
    }
    return max_len;
}


int main() {
	string str = "rudrajitmitra";
	cout<<getLongestSubstr(str)<<endl;
	return 0;
}