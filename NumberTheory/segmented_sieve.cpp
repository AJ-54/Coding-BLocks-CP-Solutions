#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

// This code if used to produce list of primes in a given segment of a and b.
// The concept is based on shifting of a and b to use the prime sieves method.
// Typically used when a and b are quite large but |b-a| lies in range of order 6.
// This allows us to create array of size |b-a|.


bool* prime_sieve(int n){
    bool* arr = new bool[n]();
    for (int i=4;i<=n;i+=2) arr[i] = true;
    for (int i=3;i<=n;i+=2){
        for (int j=i*i; j<n; j += 2*i){
            arr[j] = true;
        }
    }
    return arr;
}

void segmented_seive(ll a, ll b, bool* primes){
    bool *arr = new bool[b-a+1]();
    for (ll j=2;j*j<=b;j++){
        for (ll i=a;i<=b;i++){
            if (!primes[j]){
                if (i==j) continue;
                if (i%j==0) arr[i-a] = true;
            }
        }
    }
    for (int i=0;i<=b-a;i++) if (!arr[i]) cout << i+a << " ";
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll rootb = sqrt(b);
    bool* primes = prime_sieve(rootb);
    segmented_seive(a,b, primes);
}