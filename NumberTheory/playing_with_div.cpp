#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;

ll modular_expo(ll a, ll b){
    ll ans = 1;
    while(b>0){
        if (b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b>>=1;
    }
    return ans;
}

int main(){
    int x;
    cin >> x;
    ll arr[x],sum=1,c=0;
    for(int i=0;i<x;i++){
        cin >> arr[i];
        if (arr[i]) sum = (sum*(arr[i]+1))%MOD;
        if (arr[i]%2==0) c++;
    }
    ll powr = (sum*modular_expo(2,MOD-2))%MOD,ans=1;
    if (c == x){
        
        for(int i=0;i<x;i++){
            if(arr[i]){
                ans = (ans*((powr*arr[i]+ arr[i]/2)%MOD  + 1))%MOD;
            }
        }
        cout << ans << endl;
    }
    else{
        for(int i=0;i<x;i++){
            if(arr[i]){
                ans = (ans*((powr*arr[i])%MOD+ 1)%MOD)%MOD;
            }
        }
        cout << ans << endl;
    }

}