#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long  
using namespace std;


int main() {	
	ll t,n;
    cin >> t;
    while(t--){
        cin >> n;
        double ans=0;
        for (int j=1;j<=n;j++){           
            ans += (float)n/(float)j;
        }
       
        cout <<fixed << setprecision(2) << (float)ans << endl;
    }
    }