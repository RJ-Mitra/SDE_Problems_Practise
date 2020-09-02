//Find minimum number of coins which can be used for a given amount of money

//Given a list of coin denominations (unlimited coins of each) and an amount n, find the minimum number
//of coins of the given denominations that can be used

//Approach: Greedy
//Sort the denominations into descending order. Starting with the largest denomination
//check how many times that denomination appear within the given amount
//add the number of coins and move to the next lower denomination


#include<bits/stdc++.h>
using namespace std;

int getMinNumCoins(int n,vector<int> coins){
    sort(coins.begin(),coins.end(),greater<>());
    int total_coins = 0;
    for(int i=0;i<coins.size();++i){ //for all denominations in desc list
        while(n>=coins[i]){ //substract the denomination from total amount and update count and amount
            n-=coins[i];
            total_coins++;
        }
    }
    return total_coins;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    int n = 121;
    int res = getMinNumCoins(n,coins);
    cout<<res<<endl;
}