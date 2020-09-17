#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;

//This code produces list of primes upto n.
// The time complexity is O(nloglogn) ~ O(n)

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
    ll n,q,maxm = 0;
    cin >> n;
    for(ll p=0;p<n;p++){
        ll m,k;
        cin >>m;
        maxm = (maxm>m)?maxm:m;
        while(m>1){
            arr[primes[m]]++;
            m = m/primes[m];
        }
    }
    
    ll  xor_sum = 0;
    for  (ll i=2;i<=maxm;i++) xor_sum ^= arr[i],arr[i] = 0;
    if (xor_sum == 0) cout << "Liverbird" << endl;
    else cout << "Mancunian" << endl;
    
    }

}
