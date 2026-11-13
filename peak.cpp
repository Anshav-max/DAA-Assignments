#include<bits/stdc++.h>
using namespace std;

int peak(vector<int>& nums){
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])return nums[mid];
        else if(nums[mid] < nums[mid+1])low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    vector<int>nums = {5,4,3,2,1};
    int ans = peak(nums);
    if(ans == -1)cout<<"ERROR!!No Peak Element Found"<<endl;
    else cout<<ans;
    return 0;
}