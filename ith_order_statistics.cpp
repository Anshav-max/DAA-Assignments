#include<bits/stdc++.h>
using namespace std;

int randomized_partition(vector<int>& nums, int p, int r){
    int random = (p + (rand())%(r - p + 1)); // random selection of index
    swap(nums[random],nums[r]);
    
    // Partition
    int pivot = nums[r];
    int i = p - 1;
    for(int j = p; j < r;j++){
        if(nums[j] <= pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[r]);
    return i+1;
}

int randomized_select(vector<int>& nums, int p, int r, int i){

    if(p == r)return nums[p];

    int q = randomized_partition(nums,p,r);
    int k = (q - p + 1);
    if(i == k)return nums[q];
    else if(i < k)randomized_select(nums,p,q-1,i);
    else randomized_select(nums,q+1,r,i-k);
}
int main(){

    vector<int>nums = {20,43,15,78,89,7,37,92,62,58};
    int x = randomized_select(nums,0,nums.size()-1,9);
    cout<<x<<endl;
    return 0;
}