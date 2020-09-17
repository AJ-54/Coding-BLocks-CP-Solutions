#include<iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int ans = 0;;
void compute(int n, int r, string str, bool b){
    //Base Case
    if (r==n) ans++;

    else{
        if (b) compute(n,r+1,str+"a",!b);
        else{
            compute(n,r+1,str+"b",!b);
            compute(n,r+1,str+"a",b);
        }
    }
}

int main(){
    int t,n;
    cin >>t;
    for(int j=1;j<=t;j++){
        cin >> n;
        compute(n,0,"",false);
        cout << "#"<<j<<" : "<< ans << endl;
        ans = 0;
    }
}