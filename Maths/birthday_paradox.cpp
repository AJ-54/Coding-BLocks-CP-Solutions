#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;

int main() {	
    float num = 365;
    float den = 365;

    float p,ans=1;
    cin >> p;

    int n=0;
    while (ans>1-p){
        ans=ans*num/den;
        num--;
        n++;
    }
    if (p==1) cout << 366 << endl;
    else cout << n << endl;
     }
