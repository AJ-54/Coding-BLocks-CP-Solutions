#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll unsigned long long  
using namespace std;

// ll factorial(ll n){
//     if (n==0) return 1;
//     n = n*factorial(n-1);
//     return n;
// }

ll power(ll n, ll p){
    if (p==0) return 1;
    ll sp = power(n,p/2);
    sp *=sp;
    if (p&1) return n*sp;
    return sp;
}

int main() {	
       ll t,a,n,p;
       cin >> t;
       while(t--){
           cin >> a>>n>>p;
           vector<int> vec;
           ll val=a;
           for(int j=1; j<=n; j++){
            // ll temp = factorial(j);
            val = power(val,j);
            cout <<j <<' ';
            ll temp = val%p;
            cout <<val <<' '<<temp << endl; 
    //         if (j==1) vec.push_back(temp);
    //         else{
    //         if (temp==vec[0]) break;
    //         else vec.push_back(temp);
    //        }
    //        }
    //        int period = vec.size();
    //        if (n<=period) cout << vec[n-1] << endl;
    //        else{
    //        if (n%period == 0) cout << vec[period-1] << endl;
    //        else cout << vec[n%period -1] << endl;
       }
       }
}
            
    