/*
Given a list of stock prices where their index corresponds to the day of the stock price,
determine when to buy and sell stocks to get the maximum profit.
NOTE: A stock must be bought once before it can be sold.
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size()<=1) return 0; //base case if price vector has only one element or less
    int min_buy;
    int min_buy_index = 0;
    int max_sell;
    int max_sell_index;
    int max_profit = INT_MIN;
    int i = 0;
    
    while(i<prices.size()){ //repeat so that if a stock of lower value is found after after an initial low buy point, it can be picked up again
        while(i<prices.size()-1 && prices[i+1]<=prices[i]){
            ++i;
        } //finds the day with the minimum stock value so that it can be bought on that day
    
        min_buy_index = i;
        min_buy = prices[i];

        max_sell = min_buy;
        
        for(int j=min_buy_index+1;j<prices.size();++j){ //finds the max value of stock post buy day to sell the stock for max profit
            if(prices[j]>max_sell){
                max_sell = prices[j];
                max_sell_index = j;
            }
        }
    
        max_profit = max(max_profit, (max_sell - min_buy)); //find the maximum profit
        ++i;
    }
    return max_profit;
}


int main(){
    vector<int> vec = {7,1,5,3,6,4};
    int res = maxProfit(vec);
    cout<<"Max profit: "<<res<<endl;
}
