#include<iostream>
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull mul(ull a, ull b, ull mod) 
{ 
    ull res = 0;
    a %= mod; 
  
    while (b) 
    { 
        if (b & 1) 
            res = (res + a) % mod; 
        a = (2 * a) % mod; 
  
        b >>= 1; 
    } 
  
    return res; 
} 

ull power(ull a, ull b, ull m){
    ull ans = 1;
    while(b>0){
        if (b&1) ans = mul(ans,a,m);
        a = mul(a,a,m);
        b>>=1;
    }
    return ans;
}

bool millertest(ull d, ull n){
    // d is an odd number such that  d*2^r = n-1 
    // for some r >= 1 
    // Pick a random number in [2..n-2] 
    // Corner cases make sure that n > 4 
    ull a = 2 + rand()%(n-4);

    //compute a^d % n
    ull x = power(a,d,n);

    if (x==1 || x==n-1) return true;

    // Keep squaring x while one of the following doesn't 
    // happen 
    // (i)   d does not reach n-1 
    // (ii)  (x^2) % n is not 1 
    // (iii) (x^2) % n is not n-1

    while(d!=n-1){
        x = mul(x,x,n);
        d*=2;

        if (x==1) return false;
        if (x==n-1) return true;
    }

    //return composite
    return false;
 
}
bool isprime(ull n, int k){
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.

    //Corner Cases
    if (n<=1 || n==4) return false;
    if (n<=3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    ull d = n-1;
    while(d%2==0) d/=2;

    // Iterate given number k times;
    for (ull i=0;i<k;i++){
        if (!millertest(d,n)) return false;
    }
    return true;

}

int main(){
    int n;
    cin >> n;
    while(n--){
        ull m;
        cin >> m;
        if (isprime(m,3)) cout << "YES" << endl;
        else cout <<  "NO" << endl;
    }
    return 0;
}