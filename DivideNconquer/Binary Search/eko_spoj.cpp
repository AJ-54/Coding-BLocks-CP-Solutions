#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[1000001];
ll n,m;
bool ispossible(int val){
    ll temp = 0;
    for (ll i=0;i<n;i++){
        if (arr[i] > val) temp += (arr[i] - val);
        if (temp >= m) return true;
    }
    return false;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    int s = arr[0], e=arr[n-1];
    int ans = 0;
    while (s<=e){
        int mid = (e+s)/2;
        if (ispossible(mid)){
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    cout << ans << endl;
}