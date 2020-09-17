#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    ll ans=0;
    for (int i=0;i<n;i++){
        ll temp;
        cin >> temp;
        if (i!=n-1)ans =(ans+(temp)%MOD)%MOD;
    }
    cout << ans <<  endl;
}