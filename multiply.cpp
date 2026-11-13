#include<bits/stdc++.h>
using namespace std;

long long Traditional(long long x, long long y){
    if(x < 10 || y < 10){
        return x * y;
    }

    int n = 0;
    long long temp = x;
    while(temp > 0){
        n++;
        temp /= 10;
    }

    long long r = pow(10,n/2);
    long long xh = x / r;
    long long xl = x % r;

    long long yh = y / r;
    long long yl = y % r;

    long long a = Traditional(xh,yh);
    long long b = Traditional(xh,yl);
    long long c = Traditional(xl,yh);
    long long d = Traditional(xl,yl);

    return a*r*r + (b+c)*r + d;
}

long long Karastuba(long long x, long long y){
    if(x < 10 || y < 10){
        return x * y;
    }

    int n = 0;
    long long temp = x;
    while(temp > 0){
        n++;
        temp /= 10;
    }

    long long r = pow(10,n/2);
    long long xh = x / r;
    long long xl = x % r;

    long long yh = y / r;
    long long yl = y % r;

    int a = Karastuba(xh,yh);
    int b = Karastuba(xl,yl);
    int e_ = Karastuba(xh+xl,yh+yl);
    int e = e_ - a - b;

    return a*r*r + e*r + b;
}

int main(){
    long long x,y;
    cout<<"Enter two n-digit number:\n";
    cin>>x>>y;

    long long ans1, ans2;
    ans1 = Traditional(x,y);
    ans2 = Karastuba(x,y);

    cout<<"Traditional Approach:"<<ans1<<"\nKarastuba Approach:"<<ans2;
    return 0;
}