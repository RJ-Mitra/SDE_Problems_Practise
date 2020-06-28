//find the column number in excel for a given column label (and the reverse)
//E.g. A is 1, Z is 26, AA is 27

#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string s) {
        int n = s.size();
        char first = s[0];
        if(n<2) return (first-'A')+1; //if the string has only one char, it means we can directly get the column number (alphabet number)
        long long char_val = 0;
        for(int i=0;i<s.size();++i){
            char_val = 26*char_val+(s[i]-'A'+1); //calculate value of all characters (26 * char_val + string[i] - 'A' + 1) (str[i]-'A' gives alphabet number beginning with 0, so we add 1)
        }
        return char_val;
    }


string numberToTitle(int num){
    string s = "";
    int i = 0;
    int rem = 0;
    while(num>0){//continue until num is greater than 0
        rem = num%26;
        if(rem==0){
            s.insert(0,1,'Z'); //if rem == 0, it means char digit is Z
            num=(num/26)-1;
        }else{
            s.insert(0,1,rem-1+'A'); //gets the char from ASCII value (rem -1 gives the value, -'A' converts to char)
            num/=26;
        }
    }
    return s;
}

int main(){
    string s = "AAA";
    cout<<titleToNumber(s)<<endl;
    int num = 704;
    cout<<numberToTitle(num)<<endl;
}