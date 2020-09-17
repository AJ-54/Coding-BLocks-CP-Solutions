#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;

ll modular_expo(ll a , ll b, ll mod){
    ll ans = 1;
    while(b>0){
        if (b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>=1;
    }
    return ans;
}
ll fact_mod(ll n,  ll mod){
    if (n==1) return 1;
    return (n*fact_mod(n-1))%mod;
}
ll ncr_modular(ll n, ll r, ll mod){
    ll num = 1;
    for (ll i=(n-r+1);i<=n;i++){
        num = (num*i)%mod;
    }
    ll fact = fact_mod(r);
    ll fact_pow = modular_expo(fact, mod - 2);
    ll ans = (num*fact_pow)%mod;
    return ans;    
}

void totient(ll n){
    phi[1] = 1;
    for (ll i = 2;i<=n;i++) phi[i] = i;
    for (ll i = 2;i<=n;i++){
        if (phi[i] == i){
            for (ll j = i; j<=n; j+=i){
                phi[j] = (phi[j]*(i-1)/i);
            }
        }
    }
}