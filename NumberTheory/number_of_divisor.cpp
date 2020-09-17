#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;

//

ll primes[1000001]={0};
ll arr[1000001] = {0};

void sieve(ll n){
    primes[1] = 1;
    for (ll i=2;i<=n;i++){
            for (ll j=i;j<=n;j+=i){
                if (primes[j] == 0){
                primes[j] = i;
            }
        }
    }
    
}

int main(){
    sieve(1000000);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
       
        ll ans = 1,maxm=0;
        for(ll k=0;k<n;k++){
            ll t;
            cin >> t;
            maxm = (maxm>t)?maxm:t;
            while(t>1){
                arr[primes[t]]++;
                t = t/primes[t];
            }
        }
        for (ll i=2;i<=maxm;i++){
            ans = (ans*(arr[i]+1))%MOD;
            arr[i] = 0;
            // cout <<i << " "<< arr[i] << endl;
        }
        cout << ans << endl;
    }
   
}

