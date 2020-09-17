#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;
// {1,2,4,6,7,8,9}
vector<ll> subsets(vector<ll> v){
    // for (ll j =0; j< v.size(); j++)cout << v[j] << ' ';cout << endl;
    vector<ll> sums;
    ll n = v.size();
    for (ll j=0; j< (1<<n);j++){
        ll sum = 0,bit=j,temp=0;
        while (bit>0){
            if (bit&1) sum+=v[temp];
            temp++;
            bit = bit>>1;
        }
        sums.push_back(sum);
    }
    // for (ll j =0; j< sums.size(); j++)cout << sums[j] << ' ';cout << endl;
    
    return sums;
}
int main() {	
    ll n,a,b;
    vector<ll> vl,vu;
    cin>>n>>a>>b;
    ll l=n/2;
    ll u=n-l;
    for (ll j=0;j<l;j++){
        ll temp;
        cin >> temp;
        vl.push_back(temp);
    }
    for (ll j=0;j<u;j++){
        ll temp;
        cin >> temp;
        vu.push_back(temp);
    }
    ll ans=0;
    //li,lf,ui,uf,ti,tf;
    vector<ll> svl,svu;
    svl = subsets(vl);
    svu = subsets(vu);
    // for (ll j =0; j< svl.size(); j++)cout << svl[j] << ' ';cout << endl;
    
    // sort(svl.begin(),svl.end());
    sort(svu.begin(),svu.end());
    // for (ll j =0; j< svu.size(); j++)cout << svu[j] << ' ';cout << endl;
    
    for(ll j=0;j<svl.size();j++){
        ll low = a-svl[j];
        ll high = b-svl[j];
        // cout<< "To find" << low << ' ' << high << endl;
        ll ti = lower_bound(svu.begin(),svu.end(),low)-svu.begin();
        ll tf = upper_bound(svu.begin(),svu.end(),high)-svu.begin();
        // cout << ti << ' ' << tf << endl;
        ans += tf-ti;
        // cout << ans << endl;
    }
    cout<< ans << endl;
     }
