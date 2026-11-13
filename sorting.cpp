#include<bits/stdc++.h>
using namespace std;

// INSERTION SORT
void insertion_sort(vector<int>&nums){
    int n = nums.size();
    for(int i = 1; i < n;i++){
        int x = nums[i];
        int j = i-1;
        while(j >= 0){
            if(nums[j] > x)swap(nums[j],nums[j+1]);
            else break;
            j--;
        }
        nums[j+1] = x;
    }
}

// MERGE SORT
void merge(vector<int>&nums,int p, int q, int r){
    vector<int>temp;
    int i = p;
    int j = q + 1;
    while(i <= q && j <= r){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i]);
            i++;
        }
        else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i <= q){
        temp.push_back(nums[i]);
        i++;
    }
    while(j <= r){
        temp.push_back(nums[j]);
        j++;
    }
    for(int k = p; k <= r;k++){
        nums[k] = temp[k-p];
    }
}

void ms(vector<int>&nums,int p , int r){
    if(p < r){
        int q = p + (r - p)/2;
        ms(nums,p , q);
        ms(nums,q+1,r);
        merge(nums,p,q,r);
    }
}

void merge_sort(vector<int>&nums){
    int n = nums.size();
    int p = 0;
    int r = n - 1;
    ms(nums,p,r);
}

// QUICK SORT
int partition(vector<int>&nums,int p, int r){
    int pivot = nums[p];
    int i = p+1;
    int j = r;
    while(i <= j){
        while(i <= r && nums[i] <= pivot)i++;

        while(j >= p+1 && nums[j] > pivot)j--;

        if(i < j)swap(nums[i],nums[j]);
    }
    swap(nums[p],nums[j]);
    return j;
}

void qs(vector<int>&nums,int p, int r){
    if(p < r){
        int q = partition(nums,p,r);
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
    vector<int>nums;

     // Reading input from .txt file
    ifstream file("input.txt");

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
        nums.push_back(val);
    }

    file.close();

    cout<<"Initial input data :";
    display(nums);

    int choice;

    do{
        cout<<"SORTING:"<<endl;
        cout<<"INSERTION SORT : enter 1"<<endl;
        cout<<"MERGE SORT : enter 2"<<endl;
        cout<<"QUICK SORT : enter 3"<<endl;
        cout<<"EXIT : enter 4"<<endl;

        cin>>choice;

        switch(choice){
            case 1:
                insertion_sort(nums);
                display(nums);
                cout<<"Insertion Sort Executed"<<endl;
                break;
            case 2:
                merge_sort(nums);
                display(nums);
                cout<<"Merge Sort Executed"<<endl;
                break;
            case 3:
                quick_sort(nums);
                display(nums);
                cout<<"Quick Sort Executed"<<endl;
                break;
            case 4:
                cout<<"Program Terminated"<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice != 4);

    return 0;
}