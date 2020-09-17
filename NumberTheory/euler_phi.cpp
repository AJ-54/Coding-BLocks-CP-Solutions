#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void totient(ll n){
    ll phi[n+1] = {0};
    phi[1] = 0;
    for (ll i = 2;i<=n;i++) phi[i] = i;
    for (ll i = 2;i<=n;i++){
        if (phi[i] == i){
            for (ll j = i; j<=n; j+=i){
                phi[j] = (phi[j]*(i-1)/i);
            }
        }
    }
    cout << phi[n] << endl;
}

int main(){
    ll n;
    cin >> n;
    totient(n);
}