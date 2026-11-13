#include<bits/stdc++.h>
using namespace std;

// NON-RECURSIVE:
vector<vector<int>> MCM(vector<int>& p){
    int n = p.size()-1;

    vector<vector<int>>m(n+1,vector<int>(n+1));
    vector<vector<int>>s(n+1,vector<int>(n+1));

    for(int i = 0 ; i <= n;i++){
        m[i][i] = 0;
    }

    for(int l = 2; l <= n;l++){
        for(int i = 1; i <= n-l+1;i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k < j;k++){
                int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    
    return s;
}


// RECURSIVE:
int MCM2(vector<int>& p, vector<vector<int>>& m, vector<vector<int>>&s,int i,int j){
    if(i == j){
        return 0;
    }

    if(m[i][j] != -1){
        return m[i][j];
    }

    int ans = INT_MAX;
    for(int k = i; k < j;k++){
        int q = MCM2(p,m,s,i,k) + MCM2(p,m,s,k+1,j) + p[i-1]*p[k]*p[j];
        if(q < ans){
            ans = q;
            s[i][j] = k;
        }
    }

    return m[i][j] = ans;
}



void POP(vector<vector<int>>& s, int i, int j){
    if(i == j){
        cout<<"A"<<i;
        return;
    }

    cout<<"(";
    POP(s,i,s[i][j]);
    POP(s,s[i][j]+1,j);
    cout<<")";
}


int main(){
    vector<int>p = {5,4,6,2,7};
    int n = p.size()-1;
    vector<vector<int>>s1 = MCM(p);

    cout<<"Optimal Parenthesis by Non-Recursive Approach:\n";
    POP(s1,1,n);
    cout<<endl;
    vector<vector<int>>m(n+1,vector<int>(n+1,-1));
    vector<vector<int>>s(n+1,vector<int>(n+1));
    for(int i = 0 ; i <= n;i++){
        m[i][i] = 0;
    }

    MCM2(p,m,s,1,n);
    cout<<"Optimal Parenthesis by Recursive Approach:\n";
    POP(s,1,n);
    return 0;
}