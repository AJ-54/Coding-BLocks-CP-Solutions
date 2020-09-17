#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

//This function will be using chinese remainder theorem to compute value of x.
// x is such that x = 1(mod 2) .... n so on...

ll chinese_remainder(vector<ll> num, vector<ll> rem){

    //define pp vector;
    vector<ll> pp;
    pp.clear();
    ll prod = 1;
    for (ll i=0;i<num.size();i++) prod *= num[i];
    for (ll i=0;i<num.size();i++){
        pp.push_back(prod/num[i]);
    }

    //define inverse vector
    // inv is modular inverse of pp[i] wrt num[i]
    vector<ll>inv;
    inv.clear();
    for (ll i=0;i<num.size();i++){

    }

}

int main(){

}