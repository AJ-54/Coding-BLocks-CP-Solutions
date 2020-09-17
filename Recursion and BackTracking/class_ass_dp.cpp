#include<iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;


int compute(int n, int r, string str, bool b){
    
    int arra[n+1], arrb[n+1]; 
    arra[0] = arrb[0] = 0;
    arra[1] = arrb[1] = 1;
    for (int j=2;j<=n;j++){ 
        arra[j] = arra[j-1] + arrb[j-1];
        arrb[j] = arra[j-1];
    }

    return arra[n] + arrb[n];    
    
    }

int main(){
    int t,n;
    cin >>t;
    for(int j=1;j<=t;j++){
        cin >> n;
        int ans = compute(n,0,"",false);
        cout << "#"<<j<<" : "<< ans << endl;
    }
}