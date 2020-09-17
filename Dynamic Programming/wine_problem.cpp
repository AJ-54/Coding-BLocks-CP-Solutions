#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll arr[1000000];
ll dp[3000][3000];

ll maxProfit(ll start, ll end, ll year){

    //Base Case
    if (start>end) return 0;

    //If solution is present in dp!
    if(dp[start][end] != 0) return dp[start][end];

    ll front = arr[start]*year + maxProfit(start+1,end,year+1);
    ll rear = arr[end]*year + maxProfit(start,end-1,year+1);

    return dp[start][end] = max(front,rear);

}

ll maxProfit_DP(ll n){
    for (ll i=0;i<n;i++) dp[i][i] = n*arr[i];
    ll i=0,j=1;
    while(j<n){
        ll t=j;
        while(j<n){
            ll year = n-(j-i);
            dp[i][j] = max(arr[i]*year + dp[i+1][j],arr[j]*year + dp[i][j-1]);    
            i++,j++;
        }
        j = t + 1;
        i = 0;
    }
    return dp[0][n-1];
}

ll maxprofit_dp(ll n){

    for (ll i=0;i<n;i++) dp[i][i] = n*arr[i];

    for (int len=2;len<=n;len++){
        int start = 0;
        int endwindow = n-len;
        int year = n-len+1;
        while(start<=endwindow){
            int end = start+len-1;
            dp[start][end] = max(
                arr[start]*year + dp[start+1][end],
                arr[end]*year + dp[start][end-1]
            );
            start++;
        }
    }

    return dp[0][n-1];
}

int main(){
    ll n;
    cin >> n;
    memset(dp,0,sizeof(dp));
    for (ll i=0;i<n;i++) cin>> arr[i];
    // ll ans = maxProfit(0,n-1,1);
    ll ans = maxprofit_dp(n);
    memset(dp,0,sizeof(dp));
    ll ans_dp = maxProfit_DP(n);
    cout << ans_dp << endl;
    cout << ans << endl;

}