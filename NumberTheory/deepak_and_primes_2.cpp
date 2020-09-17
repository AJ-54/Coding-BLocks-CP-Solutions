#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

// This code if used to produce list of primes in a given segment of a and b.
// The concept is based on shifting of a and b to use the prime sieves method.
// Typically used when a and b are quite large but |b-a| lies in range of order 6.
// This allows us to create array of size |b-a|.

vector<ll> p;
void prime_sieve(ll n){
    bool mark[n+1];
    memset(mark,true,sizeof(mark));
    p.push_back(2);
    for (ll i=3;i<=n;i+=2){
		if (mark[i]){
			p.push_back(i);
        for (ll j=i*i; j<=n; j += 2*i){
            mark[j] = false;
        }
    } 
	}  
}


void segmented_seive(ll a, ll b){
    bool arr[b-a+1] = {0};
    for (ll j=0;j<p.size();j++){
			ll low = (ceil(a/(double)p[j]))*p[j];
           
        for (ll i=low;i<=b;i+=p[j]){
             if (i != p[j]) arr[i-a] = true;
            }
                
		}
    for (ll i=0;i<=b-a;i++) if (!arr[i] && (i+a)>1) cout << i+a << endl;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    prime_sieve(31623);
    int t;
    cin >> t;
    while (t--){
    ll a,b;
    cin >> a >> b;
    segmented_seive(a,b);
    cout << endl;
    }
    return 0;
}