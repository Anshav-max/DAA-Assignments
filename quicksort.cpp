#include<bits/stdc++.h>
using namespace std;

int first_Pivot(vector<int>&nums,int p,int r){
    int pivot = nums[p];
    int i = p+1;
    int j = r;
    while(i <= j){
        while(i <= j && nums[i] <= pivot)i++;
        while(i <= j && nums[j] > pivot)j--;
        
        if(i < j)swap(nums[i],nums[j]);
    }
    swap(nums[p],nums[j]);
    return j;
}

int last_pivot(vector<int>&nums, int p, int r){
    int pivot = nums[r];
    int i = p;
    int j = r - 1;
    while(i <= j){
        while(i <= j && nums[i] <= pivot)i++;
        while(i <= j && nums[j] > pivot)j--;
        
        if(i < j)swap(nums[i],nums[j]);
    }
    swap(nums[i],nums[r]);
    return i;
}

int middle_pivot(vector<int>&nums,int p, int r){
    int pivot = nums[p+(r-p)/2];
    int i = p;
    int j = r;
    while(i <= j){
        while(nums[i] < pivot)i++;
        while(nums[j] > pivot)j--;
        
        if(i <= j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    return i;
}

void qs(vector<int>&nums,int p, int r){
    if(p < r){
        int q = middle_pivot(nums,p,r);
        qs(nums,p,q-1);
        qs(nums,q+1,r);
    }
}

void quick_sort(vector<int>&nums){
    int n = nums.size();
    int p = 0;
    int r = n - 1;
    qs(nums,p,r);
}

void display(vector<int>&nums){
    for(int i : nums)cout<<i<<" ";
    cout<<endl;
}
int main(){
    vector<int>random_array;
    vector<int>sorted_array;
    vector<int>reverse_sorted_array;

         // Reading input from .txt file
    ifstream file("sample.txt");

    if(!file){
        cout<<"ERROR!! Could Not Open tree.txt\n";
        return 1;
    }

    int n;
    file>>n;

    if(n < 0){
        cout<<"ERROR!! Invalid Size Input\n";
        file.close();
        return 1;
    }

    for(int i = 0; i < n;i++){
        int val;
        file>>val;
        random_array.push_back(val);
    }

        for(int i = 0; i < n;i++){
        int val;
        file>>val;
        sorted_array.push_back(val);
    }
        for(int i = 0; i < n;i++){
        int val;
        file>>val;
        reverse_sorted_array.push_back(val);
    }

    file.close();
    cout<<"Initial Arrays"<<endl;
    display(random_array);
    cout<<endl;
    display(sorted_array);
    cout<<endl;
    display(reverse_sorted_array);
    cout<<endl;
    
    
    cout<<"Final Arrays"<<endl;
    quick_sort(random_array);
    display(random_array);
    cout<<endl;
    quick_sort(sorted_array);
    display(sorted_array);
    cout<<endl;
    quick_sort(reverse_sorted_array);
    display(reverse_sorted_array);
    return 0;
}