#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arr[100005];
int dp[100005];

int maxprofit_DP(int n){
    dp[1] = arr[1];
    for(int i=2;i<=n;i++){
        dp[i] = arr[i];
        for(int j=1;j<=i/2;j++){
            dp[i] = max(dp[i],dp[j]+ dp[i-j]);
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    int ans = maxprofit_DP(n);
    cout << ans << endl;
    // cout << top_down(n) << endl;
}