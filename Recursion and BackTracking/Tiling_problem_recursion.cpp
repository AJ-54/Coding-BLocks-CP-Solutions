#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
#define MOD 1000000007
using namespace std;

ll score [100000] = {0};
ll compute(ll n, ll m){
    // Base Case
    if (n<=0) return 0;
    if (n==1) {
        score[n] = 1;
        return 1;
    }

    // Checks:
    if (m>n) {
        score [n] = 1;
        return 1;
    }
    else if (m==n){
        score[n] = 2;
        return 2;
    }

    //Recursive Case
    if (score[n]==0) {score[n] = (compute(n-m,m) + compute(n-1,m))%MOD;return score[n];}
    else return score[n];
}


int main(){
    ll t,n,m;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> m;
        ll ans = compute(n,m);
        cout << ans%MOD << endl;
    }
}