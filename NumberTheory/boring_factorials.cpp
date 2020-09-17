#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Fast Modulo Exponentiation
ll fastModExp(ll a, ll b, ll m){
    ll ans = 1;
    while (b>0){
        if (b&1) ans = (ans*a)%m;
        a=(a*a)%m;
        b >>= 1;
    }
    return ans;
}

ll solve(ll n, ll p){
    ll ans = -1;
    for (ll i = n+1; i<= p-1; i++){
        ll temp = fastModExp(i,p-2,p);
        ans = (ans*temp)%p;
    }
    return (ans+p);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n,p;
        cin >> n >> p;
        if (n>=p) cout << 0 << endl;
        else{
            cout << solve(n,p) << endl;
        }
    }
}