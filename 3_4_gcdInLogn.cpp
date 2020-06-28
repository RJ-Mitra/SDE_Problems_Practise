#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
    if(a == 0) return b;
    else return gcd(a%b,a);
}

int main(){
    int a = 125;
    int b = 100;
    cout<<gcd(a,b)<<endl;
    
}