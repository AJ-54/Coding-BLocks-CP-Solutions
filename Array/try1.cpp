#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ull unsigned long long  
using namespace std;
ull factorial(int val){
    if (val==1) return 1;
    val = val*factorial(val-1);
    return val;
}

int main() {	
	int t;
    cin >> t;
    for (int z=0;z<t;z++){
        int n,k;
        cin >> n >> k;
        ull ans = 1,fact;
        if ((k-1)<(n-k)){
            for(int j=n-1;j>=(n-k+1);j--){
                ans = ans*j;
            }
            fact = factorial(k-1);
        }
        else {     
            for(int p=(n-1);p>=k;p--){
                ans = ans*p;
            }
            fact = factorial(n-k);
        }
        // cout << ans << endl;
        ans = ans/fact;
        cout << ans << endl;

    }
    }