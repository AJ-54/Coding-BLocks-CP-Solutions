#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;

//This code geneerates all divisors from 1 to n.
// At each primes index, we store the smallest prime from which it is divisble.
// To extract all factors : 
// while(n>1){
// arr[primes[n]]++;
// n /= primes[n];    
// }

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