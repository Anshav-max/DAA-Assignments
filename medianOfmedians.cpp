#include<bits/stdc++.h>
using namespace std;

void insertionsort(vector<int>& nums,int l, int r){
    for(int i = l+1;i <= r; i++){
        int x = nums[i];
        int j = i - 1;
        while(j >= l){
            if(nums[j] > x){
                swap(nums[j],nums[j+1]);
            }
            j--;
        }
    }
}

int findMedian(vector<int>& nums, int l, int r){
    insertionsort(nums,l,r);
    return nums[r+1/2];
}

int medianOfmedians(vector<int>& nums,int l , int r){
    int n = r - l + 1;
    if(n <= 5){
        return findMedian(nums,l,r);
    }
    vector<int>median;
    for(int i = l; i <= r;i += 5){
        int right = min(i + 4,r);
        int m = findMedian(nums,i,right);
        median.push_back(m);
    }
    return findMedian(median,0,median.size()-1);
}

int partition(vector<int>& nums,int l, int r,int pivot){
    int idx = l;
    for(int i = l; i <= r;i++){
        if(nums[i] == pivot){
            idx = i;
            break;
        }
    }
    swap(nums[idx],nums[r]);
    int s = l - 1;
    for(int i = l; i < r;i++){
        if(nums[i] <= pivot){
            s++;
            swap(nums[s],nums[i]);
        }
    }
    swap(nums[s+1],nums[r]);
    return s+1;
}

int select(vector<int>& nums, int l, int r,int k){
    if(l == r)return nums[l];

    int pivot = medianOfmedians(nums,l,r);
    int q = partition(nums,l,r,pivot);
    int rank = q - l + 1;
    if(rank == k){
        return nums[q];
    }
    else if(k < rank)return select(nums,l,q-1,k);
    return select(nums,q+1,r,k-rank);
}

int main(){
    vector<int>nums = {20,43,15,78,89,7,37,92,62,58};
    int x = select(nums,0,nums.size()-1,10);
    cout<<x<<endl;
    return 0;
}