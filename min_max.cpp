#include<bits/stdc++.h>
using namespace std;

pair<int,int> min_max(vector<int>& nums,int low, int high){
    if(low == high){
        return {nums[low],nums[low]};
    }
    
    if(high == low + 1){
        if(nums[high] > nums[low]){
            return {nums[low],nums[high]};
        }
        return {nums[high],nums[low]};
    }

    int mid = low + (high - low)/2;

    pair<int,int> left = min_max(nums,low,mid);
    pair<int,int> right = min_max(nums,mid+1,high);

    int mini = min(left.first,right.first);
    int maxi = max(left.second,right.second);

    return {mini,maxi};
}
int main(){
    vector<int> nums = {20,43,15,78,89,7,37,92,62,58};

    pair<int,int>ans = min_max(nums,0,nums.size()-1);

    cout<<"Minimun:"<<ans.first<<endl;
    cout<<"Maximum:"<<ans.second<<endl;
    return 0;
}