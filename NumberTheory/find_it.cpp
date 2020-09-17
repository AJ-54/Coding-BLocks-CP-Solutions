#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;

//This sieve produces divisors of all number from 1 to n.

ll arr[1000001] = {0};

void sieve(ll n){
    arr[n]++;
    if (n != 1) arr[1]++;
    for  (ll i=2;i*i<=n;i++){
        if (i*i == n) arr[i]++;
        else{
            if (n%i == 0){
                arr[i]++;
                arr[n/i]++;
            }
        }
    }
}


int main(){
    ll n,q;
    cin >> n;
    for(ll p=0;p<n;p++){
        ll t,k,s=0;
        cin >> t;
        sieve(t);
    }
    cin >> q;
    for (ll j=0;j<q;j++){
        ll h;
        cin >> h;
        cout << arr[h] << endl;

    }
    
    
   
}

