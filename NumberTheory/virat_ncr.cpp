#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;

ll modular_expo(ll a , ll b){
    ll ans = 1;
    while(b>0){
        if (b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return ans;
}

ll fact_mod(ll n){
    if (n==1) return 1;
    return (n*fact_mod(n-1))%MOD;
}

int main(){
    ll n,r;
    cin >> n >> r;
    ll num = 1;
    for (ll i=(n-r+1);i<=n;i++){
        num = (num*i)%MOD;
    }
    ll fact = fact_mod(r);
    ll fact_pow = modular_expo(fact, MOD - 2);
    ll ans = (num*fact_pow)%MOD;
    cout << ans << endl;
    
}