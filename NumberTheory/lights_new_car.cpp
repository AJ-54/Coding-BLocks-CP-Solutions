#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll stringtoint(string s, ll m){

    ll ans = 0;
    for (int i=0;i<s.length();i++){
        ans = (ans*10 + (s[i] - '0'))%m;
    }
    return ans;
}

ll power(ll a, ll b){

    ll ans = 1;
    while (b>0){
        if (b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return ans%MOD;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string a,b;
        cin >> a >> b;
        ll x,y;
        x = stringtoint(a,MOD);
        y = stringtoint(b, MOD -1);
        cout << power(x,y) << endl;
    }
}