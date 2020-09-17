#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using  namespace std;

ll mod_gcd(ll a, ll b){
    return (b==0)?a:mod_gcd(b,(a%b))%MOD;
}

int main(){
    int n;
    cin >> n;
    vector<ll> v;
    for (int i=0;i<n;i++){
        ll m;
        cin >> m;
        ll ans = 1;
        for(ll j=0;j<m;j++){
            ll temp;
            cin >> temp;
            ans = (ans*(temp)%MOD)%MOD;
        }
        v.push_back(ans);
    }
    ll ans = v[0];
    for(ll i=1;i<v.size();i++){
        ans = mod_gcd(ans%MOD,v[i]);
    }
    cout << ans << endl;
}