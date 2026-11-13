#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&nums,int p, int mid1, int mid2, int r){
    vector<int>temp;
    int i = p;
    int j = mid1 + 1;
    int k = mid2 + 1;

    while (i <= mid1 && j <= mid2 && k <= r) {
    if (nums[i] <= nums[j] && nums[i] <= nums[k])
        temp.push_back(nums[i++]);
    else if (nums[j] <= nums[i] && nums[j] <= nums[k])
        temp.push_back(nums[j++]);
    else
        temp.push_back(nums[k++]);
    }

    while (i <= mid1 && j <= mid2)
        temp.push_back(nums[i] <= nums[j] ? nums[i++] : nums[j++]);

    while (j <= mid2 && k <= r)
        temp.push_back(nums[j] <= nums[k] ? nums[j++] : nums[k++]);

    while (i <= mid1 && k <= r)
        temp.push_back(nums[i] <= nums[k] ? nums[i++] : nums[k++]);

    while (i <= mid1) temp.push_back(nums[i++]);
    while (j <= mid2) temp.push_back(nums[j++]);
    while (k <= r) temp.push_back(nums[k++]);

    for(int i = p; i <= r;i++){
        nums[i] = temp[i - p];
    }
}

void ms(vector<int>&nums, int p, int r){
    if(p < r){
        int third = (r - p) / 3;
        int mid1 = p + third;
        int mid2 = p + 2 * third + 1;

        if(mid2 > r)mid2 = r;

        ms(nums,p,mid1);
        ms(nums,mid1+1, mid2);
        ms(nums,mid2+1,r);
        merge(nums,p,mid1,mid2,r);
    }
}

void merge_sort(vector<int>& nums){
    int n = nums.size();
    int p = 0;
    int r = n - 1;
    ms(nums,p,r);
}

void display(vector<int>&nums){
    for(int i : nums)cout<<i<<" ";
    cout<<endl;
}
int main(){
    vector<int>nums = {9,8,7,6,5,4,3,2,1};
    merge_sort(nums);
    display(nums);
    return 0;
}