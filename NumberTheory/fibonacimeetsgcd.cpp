#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> c(3,vector<ll>(3));
    for (int i = 1; i<3;i++){
        for (int j =1; j<3;j++){
                c[i][j] = 0;
            for (int k =1; k<3;k++){
                c[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return c;
}

vector<vector<ll>> pows(vector<vector<ll>> v, ll p){
    if (p == 1) return v;
    if (p&1) return multiply(v,pows(v,p-1));
    else{
        vector<vector<ll>> sv = pows(v,p/2);
        return  multiply(sv,sv);
    }
}

ll compute(ll n){
    if (n==1|n==2) return 1;
    // k = 2;
    // F1 vector:
    vector<ll> F1(3);
    F1[1] = 1,F1[2] = 1;

    // T-matrix
    vector<vector<ll>> T(3,vector<ll>(3));
    for (int i=1;i<3;i++){
        for (int j=1;j<3;j++){
            if (i!=2){
            if (i+1==j) T[i][j] = 1;
            else T[i][j] = 0;
            }
            else T[i][j] = 1;
    }
}

    T = pows(T,n-1);
    ll ans = 0;
    for (int i = 1;i<3;i++) ans += T[1][i]*F1[i];
    return ans;
}

ll fib(ll n){
    return compute(n);
}

int main(){
    ll n,q;
    cin >> n >> q;
    ll fib_arr[n];
    for (int i=0;i<n;i++){
        cin >> fib_arr[i];
    }
    for (int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        ll ans = 0;
        for (int i=l-1;i<=r-1;i++){
            ans = gcd(fib_arr[i],ans);
        }
        cout << fib(ans)%MOD << endl;
    }
}