#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    vector<pair<int,int>>st(n,{-1,-1}); // to store left max and right max of each bar
    
    int lmax = height[0]; // left maximum
    for(int i = 1; i < n - 1; i++){
        if(height[i] < lmax)st[i].first = lmax;
        else lmax = height[i];
    }

    int rmax = height[n-1]; // right maximum
    for(int i = n-2; i >= 1; i--){
        if(height[i] < rmax)st[i].second = rmax;
        else rmax = height[i];
    }

    int c = 0; // trap count
    for(int i = 1; i < n-1 ; i++){
        int m = min(st[i].first,st[i].second);
        if(m > 0){
            c += (m - height[i]);
        }
    }
    return c;
}

int main(){
    vector<int> height = {1000,99,98,90,2,1,1000};
    int ans = trap(height);
    cout<<ans;
    return 0;
}