#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll unsigned long long  
using namespace std;
// Catalan Numbers - Vast application in market
int main() {	
        int n;
        ll ans=1;
        cin >> n;
        ll catalan[n];
        catalan[0] = catalan[1] = 1;
        for (int i=2; i<=n; i++) {
            catalan[i] = 0;
            for (int j=0; j < i; j++) {
                catalan[i] += (catalan[j] * catalan[i-j-1]);
                // if (catalan[i] >= MOD) {
                //     catalan[i] -= MOD;
                // }
            }
        }
        cout << catalan[n] <<  endl;
}
            
    