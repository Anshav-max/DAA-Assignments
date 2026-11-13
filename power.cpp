#include<bits/stdc++.h>
using namespace std;
// for divide and conquer approach the n must be non negative integer
long double pow(long double x, int n){ // X^n
    if(n == 0)return 1;

    if(n % 2 == 0){
        return pow(x,n/2) * pow(x,n/2);
    }
    return x * pow(x,n/2) * pow(x,n/2);
}

int main(){
    long double x;
    int y;
    cout<<"Enter base number:"<<endl;
    cin>>x;
    cout<<"Enter power integer:"<<endl;
    cin>>y;
    long double ans;
    if(y < 0){
        ans =1 / pow(x,y);
    }
    else ans = pow(x,y);
    cout<<ans;
    return 0;
}