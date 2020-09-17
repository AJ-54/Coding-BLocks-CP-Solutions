#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];

// This is a bottom up solution for longest pallindromic subsequence 
int main(){
    string s;
    cin >> s;
    int n = s.size();
    // Base Case :
    memset(dp,0,sizeof(dp));
    for (int i = 0; i<n;i++) dp[i][i] = 1;

    for (int len=2;len<=n;len++){
        for (int i=0;i<=n-len;i++){
            int j = i + len - 1;
            if (s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else {
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    cout << dp[0][n-1] << endl;

}