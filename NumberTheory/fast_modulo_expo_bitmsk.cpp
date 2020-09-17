#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll modular(ll a, ll b, ll m){
    ll ans = 1;
    while (b>0){
        if (b&1) {
            ans = (ans*a)%m;
        }
        a = (a*a)%m;
        b >>=1;
    }
    return ans;
}

int main(){
    ll a,b,m;
    cin >> a >> b >> m;
    cout << modular(a,b,m) << endl;
}