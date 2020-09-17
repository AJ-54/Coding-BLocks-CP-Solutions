#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
using namespace std;


// This is an application of extended euclid algorithm which computes the solution to the equations
// of the form Ax + By = GCD(A,B).

// The direct solution will be placing the values of a,m in the extended_version function.

ll x,y,GCD;
void extended_version(ll a, ll b){
    // Base Case
    if (b==0){
        x=1,y=0,GCD=a;
        return;
    }
    //Recursive Case
    extended_version(b,a%b);
    ll x1 = x, y1 = y;
    x = y1;
    y = x1 - (a/b)*y1;
    
}

void mul_inverse(ll a){
    extended_version(a,MOD);
    x = (x+MOD)%MOD;
    cout << x << endl;
}

int main(){
    ll a;
    cin >> a;
   mul_inverse(a);
}