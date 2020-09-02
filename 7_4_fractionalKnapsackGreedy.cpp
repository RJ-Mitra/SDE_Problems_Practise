//Fractional knapsack problem

//Given a list of Items with their values and weights and
//a capacity W (total weight you can carry), find the maximum
//value of items you can take (including fractions of items) to fill your knapsack

//Approach: Greedy

//Get the Items into an arr
//Sort arr on desc order of ratio of value to weight
//Starting with 1st element in sorted array, take items into knapsack
//If full item cannot be taken, take fraction of Item
//Since arr is in desc order of value:wt, we pick up the most valueable items 1st

#include<bits/stdc++.h>
using namespace std;

class Item{
    public:
        int value;
        int weight;
        Item(int value, int weight): value{value}, weight{weight}{}
};

bool comparator(Item a, Item b){ //comparator to get desc order of ratio of value to wt
    double ratio_A = (double)a.value/a.weight;
    double ratio_B = (double)b.value/b.weight;
    return ratio_A > ratio_B;
}

int fractionalKnapsack(vector<Item>& items, int W){
    double total_value = 0;
    int curr_wt = 0;
    sort(items.begin(),items.end(),comparator); //sort by desc order of ratio of value:wt
    for(int i=0;i<items.size();++i){
        if(curr_wt + items[i].weight<=W){ //it the entire item can be put in knapsack
            curr_wt+=items[i].weight;
            total_value+=items[i].value;
        }else{ //take fractional part of the item
            int rem_wt = W - curr_wt;
            total_value += items[i].value * ((double)rem_wt/items[i].weight);
        }
    }
    return total_value;
}

int main(){
    int W = 50; //Weight limit
    vector<Item> itemVec = {{60,10},{100,20},{120,30}}; //Each item with value and wight
    cout<<"Maximum value of items in fractional knapsack is: ";
    cout<<fractionalKnapsack(itemVec,W);
}