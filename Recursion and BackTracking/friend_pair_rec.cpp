#include<iostream>
#include<bits/stdc++.h>
#define ull unsigned long long int

using namespace std;
ull ans;

void compute(n,r){
    // Base Case
    if(r==n) ans++;
    else {
        
    }
}

int  main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        compute(n,0);
        cout << ans << endl;
        ans = 0;
    }
}