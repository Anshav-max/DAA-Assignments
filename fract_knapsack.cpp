#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int wt;
};

bool cmp(Item a, Item b){
    double r1 = (double)a.value / a.wt;
    double r2 = (double)b.value / b.wt;

    return r1 > r2;
}

double frac_knapsack(vector<Item>items, int W){
    sort(items.begin(),items.end(),cmp);

    int totalprofit = 0;

    for(int i = 0; i < items.size();i++){
        if(items[i].wt <= W){
            W -= items[i].wt;
            totalprofit += items[i].value;
        }
        else{
            totalprofit += ((double)items[i].value / items[i].wt) * W;
            break;
        }
    }

    return totalprofit;
}

int main(){
    vector<Item>items = {{60,10},{100,20},{120,30}};

    int W = 50;
    double ans = frac_knapsack(items,W);
    cout<<ans;
    return 0;
}