#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long  
using namespace std;
ll arr[1000001],ans[1000001],mp[1000001];


int main() {	
	ll n,answer=1;
    cin >>n;
    for(ll j=1;j<n+1;j++){
        cin >> arr[j];
        if (!(mp[arr[j]])) mp[arr[j]]=j;
    }
    // for(ll j=1;j<=n;j++) cout << arr[j] <<' '<< mp[arr[j]];cout<<endl;
    ans[1]=1;
    for(ll j=2; j<=n; j++){
        if (mp[arr[j]]==j) {ans[j]=ans[j-1]+j;answer+=ans[j];}
        else {
            ans[j] = ans[j-1]+j-mp[arr[j]];
            answer+=ans[j];
            mp[arr[j]] = j;
        }
        // cout << arr[j] << ' ' <<ans[j] << endl;
    }
    answer = answer*2 - n;
    cout << (float)answer/(float)(n*n) << endl;
    }