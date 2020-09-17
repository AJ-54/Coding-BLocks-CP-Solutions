#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long
#include<cstring>
using namespace std;

//This code produces list of primes upto n.
// The time complexity is O(nloglogn) ~ O(n)

bool* sieve(ll n){
    bool* arr = new bool[n]();
    for (ll i=4;i<n;i+=2) arr[i] = true;
    for (ll i=3;i<n;i+=2){
        for (ll j=i*i; j<n; j += 2*i){
            arr[j] = true;
        }
    }
    return arr;
}


int main(){
    ll n;
    cin >> n;
    bool *ans = sieve(n);
    for (ll i=2;i<=n;i++){ 
        if (!ans[i]){
        cout << i << endl;
    }
}
}