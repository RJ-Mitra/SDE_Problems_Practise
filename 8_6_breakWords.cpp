//Break words according to dictionary and get all combinations

//Given a sentence string and a dictionary of words, break the string
//into various combinations of words with spaces

#include<bits/stdc++.h>
using namespace std;

//fuction to compare string with dictionary contents
bool dictContains(string str, vector<string> dict){
    for(int i=0;i<dict.size();++i){
        if(str.compare(dict[i])==0) return true;
    }
    return false;
}

void wordBreak(string str, int n, vector<string> dict, string result){
    for(int i=1;i<=n;++i){
        string prefix = str.substr(0,i); //we keep adding letters to the string until it is found in the dictionary
        if(dictContains(prefix,dict)){ //if found in dictionary
            if(i == n){ //if it the last letter in the entire sentence string
                result+=prefix; //we add it to the result
                cout<<result<<endl; //we print the result and return
                return;
            }//if it is not the last letter, we add the prefix to the result with a space for word break
            wordBreak(str.substr(i,n-i),n-i,dict,result+prefix+" "); //and check recursively check for the remaining string minus the matched string
        }
    }
}

int main(){
    string str = "iloveicecreamandmango";
    vector<string> dict = {"mobile","samsung","sam","sung",
                           "man", "mango", "icecream", "and",
                           "go", "i", "love", "ice", "cream"};
    wordBreak(str,str.length(),dict,"");
}