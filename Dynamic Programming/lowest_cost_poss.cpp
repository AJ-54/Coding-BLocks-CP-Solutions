#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arr[1000][1000];
int dp[1000][1000];

int cost_DP(int n){
    //Base Case
    dp[0][0] = arr[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i==0 && j==0) continue;
            dp[i][j] = min(
                (i-1>=0)?dp[i-1][j]:INT_MAX,(j-1>=0)?dp[i][j-1]:INT_MAX
            ) + arr[i][j];
        }
    }
    return dp[n-1][n-1];
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    int ans = cost_DP(n);
    cout << ans << endl;
}