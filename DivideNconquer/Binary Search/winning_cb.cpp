#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,m,x,y;

bool ispossible(int val){

    //total coupons
    ll coupons = m + y*(n-val);
    if (coupons >= val*x) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> x >> y;
    ll s=1;
    ll e=n;
    ll ans=0;
    while(s<=e){
        ll mid = (s+e)/2;
        if (ispossible(mid)){
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    cout << ans << endl;
    
}
