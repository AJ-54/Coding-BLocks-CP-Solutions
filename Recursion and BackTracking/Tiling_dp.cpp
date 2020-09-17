#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
#define MOD 1000000007
using namespace std;


ll compute(ll n, ll m){
    // Base Case
    int score[n+1];
    score[0] = 0;
    score[1] = 1;
    for(int j=2; j<=n;j++){
        // Checks:
        if (m>j) {
            score[j] = 1;
        }
        else if (m==j){
        score[j] = 2;
        }
        else {
        score[j] = (score[j-m]+score[j-1])%MOD;
        }
    }
    return score[n];
}


int main(){
    ll t,n,m;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> m;
        ll ans = compute(n,m);
        cout << ans%MOD << endl;
    }
}