#include<bits/stdc++.h>
using namespace std;

pair<int,int> search_matrix(vector<vector<int>>& matrix, int k){
    int n = matrix.size();
    if(n == 0)return {-1,-1};
    int m = matrix[0].size();

    int i = 0;
    int j = m-1;

    while(i <= n-1 && j >= 0){
        int pt = matrix[i][j];
        if(k == pt)return {i,j};
        else if(pt > k)j--;
        else i++;
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>>matrix = {{1,5,9,10},{4,7,13,17},{6,11,14,18},{8,12,15,19}};
    int n = 3;
    while(n--){
        int x;
        cin>>x;
        pair<int,int>p = search_matrix(matrix,x);
        cout<<p.first<<' '<<p.second;
    }
    return 0;
}

// INPUT : 5 13 20

// OUTPUT : {0,1} {1,2} {-1,-1}
