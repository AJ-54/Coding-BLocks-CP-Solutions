#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long
#include<cstring>
using namespace std;

//This code produces list of primes upto n.
// The time complexity is O(nloglogn) ~ O(n)

bool primes[1000001] = {0};

void sieve(ll n){
    for (ll i=4;i<=n;i+=2) primes[i] = true;
    for (ll i=3;i<=n;i+=2){
        for (ll j=i*i; j<=n; j += 2*i){
            primes[j] = true;
        }
    }
}


int main(){
    sieve(1000001);
    ll n,p,i,j;
    cin >> n;
    while(n--){
    cin >> p;
    j = sqrt(p);
    if (((j*j == p) && !primes[j]) && p!=1){
        cout  << "YES" << endl;
    }
    else cout <<  "NO" << endl;
}
}
