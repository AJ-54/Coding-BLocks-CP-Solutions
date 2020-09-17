#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll phi[1000001];
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

int main(){
    totient(1000000);
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        cout << phi[n] << endl;
    }
}