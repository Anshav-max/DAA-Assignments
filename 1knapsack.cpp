#include<bits/stdc++.h>
using namespace std;


int kanpsack(vector<int>&value, vector<int>& weight, int W){
    int n = value.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    /*
    dp[i][w] = max(dp[i-1][w], value[i-1]+dp[i-1][w-weight[i-1]]) , if weight[i-1] <= w
             = dp[i-1][w] , otherwise
    */

    for(int i = 1; i <= n;i++){
        for(int w = 1; w <= W;w++){
            dp[i][w] = dp[i-1][w];
            if(weight[i-1] <= w){
                dp[i][w] = max(dp[i-1][w],value[i-1]+dp[i-1][w-weight[i-1]]);
            }
        }
    }
    return dp[n][W];
}

int main(){
    vector<int>value = {10,40,30,50};
    vector<int>wt = {5,4,6,3};
    int W = 10;

    int ans = kanpsack(value,wt,W);
    cout<<ans;

    return 0;
}   