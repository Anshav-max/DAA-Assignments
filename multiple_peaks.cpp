#include<bits/stdc++.h>
using namespace std;

// MULTIPLE PEAKS
void peak(vector<int>& nums,int low, int high, vector<int>& ans){
    if(low > high)return;

    int mid = low + (high - low) / 2;
    if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])ans.push_back(nums[mid]);
    peak(nums,low,mid-1,ans);
    peak(nums,mid+1,high,ans);
}

// TC = O(nlogn)

int main(){
    vector<int>nums = {5,12,7,4,9,3,4,1};
    vector<int>ans;
    peak(nums,0,nums.size()-1,ans);
    for(int i : ans)cout<<i<<endl;
    return 0;
}