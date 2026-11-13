#include<bits/stdc++.h>
using namespace std;


vector<vector<char>>b;

void print_LCS(string& X, string& Y,vector<vector<char>>& b){
    string ans = "";
    int i = b.size()-1;
    int j = b[0].size()-1;
    while(i > 0 && j > 0){
        if(b[i][j] == 'C'){
            ans += X[i-1];
            i--;
        }
        j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

void LCS(string& X, string& Y,int m, int n){
    vector<vector<int>>c(m+1,vector<int>(n+1));
    for(int i = 0; i < m+1;i++){
        c[i][0] = 0;
        vector<char>ch(n+1);
        b.push_back(ch);
    }

    for(int j = 0; j < n+1;j++){
        c[0][j] = 0;
    }

    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1;j++){
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 'C';
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 'U';
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';
            }
        }
    }

    print_LCS(X,Y,b);
}

// RECURSIVE


int LCS2(string& X, string& Y, int m, int n,
         int i, int j,
         vector<vector<int>>& c,
         vector<vector<char>>& B) {

    // Base case
    if(i == 0 || j == 0) {
        return c[i][j] = 0;
    }

    // Memoization
    if(c[i][j] != -1) {
        return c[i][j];
    }

    if(X[i-1] == Y[j-1]) {
        B[i][j] = 'C';

        return c[i][j] =
            LCS2(X, Y, m, n, i-1, j-1, c, B) + 1;
    }

    int up = LCS2(X, Y, m, n, i-1, j, c, B);
    int left = LCS2(X, Y, m, n, i, j-1, c, B);

    if(up >= left) {
        B[i][j] = 'U';
        return c[i][j] = up;
    }

    B[i][j] = 'L';
    return c[i][j] = left;
}




int main(){
    string X = "ABCBDAB";
    string Y = "BDCABA";
    int m = X.size();
    int n = Y.size();

    vector<vector<int>> c(m+1,vector<int>(n+1,-1));
    vector<vector<char>> B(m+1,vector<char>(n+1));
    

    LCS2(X,Y,m,n,m,n,c,B);

    print_LCS(X,Y,B);

    return 0;
}