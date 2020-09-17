#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll x,y,GCD;
void extended_version(ll a, ll b){
    // Base Case
    if (b==0){
        x=1,y=0,GCD=a;
        return;
    }
    //Recursive Case
    extended_version(b,a%b);
    ll x1 = x, y1 = y;
    x = y1;
    y = x1 - (a/b)*y1;
    
}

void mul_inverse(ll a,ll MOD){
    extended_version(a,MOD);
    x = (x+MOD)%MOD;
}

// ll modular_expo(ll a , ll b, ll MOD){
//     ll ans = 1;
//     while(b>0){
//         if (b&1) ans = (ans*a)%MOD;
//         a = (a*a)%MOD;
//         b >>=1;
//     }
//     return ans;
// }

void inverse_euler(ll a, ll m){
    mul_inverse(a,m);
}
ll k;
void chinese_remainder(vector<ll> num, vector<ll> rem){
    ll ans = 0,prod = 1;
    vector<ll> pp(k+1,0),inv(k+1);
    for (ll i=1;i<=k;i++) prod = prod*num[i];
    for (ll i=1;i<=k;i++) pp[i] = prod/num[i];
    for (ll i=1;i<=k;i++) inverse_euler(pp[i],num[i]),inv[i] = x;
    for (ll i=1;i<=k;i++) ans = (ans + (rem[i]*pp[i]*inv[i])%prod)%prod;

    cout << ans << endl;
}

int main(){
    cin >> k;
    vector<ll> num(k+1,0),rem(k+1,0);
    for (ll i=1;i<=k;i++) cin >> num[i];
    for (ll i=1;i<=k;i++) cin >> rem[i];
    chinese_remainder(num,rem);
}