#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
// This is a top to bottom approach.
int dp[1005][1005];

int solve(string s, int start, int end){
    // Base Case
    if (end<start) return 0;
    if (start==end){
        return 1;
    }

    //If solution is present in dp
    if (dp[start][end] != -1){
        return dp[start][end];
    }

    // If not in dp, then compute and store in dp and return
    if (s[start] == s[end]){
        return dp[start][end] = solve(s,start+1,end-1) + 2;
    }
    else {
        return dp[start][end] = max(solve(s,start+1,end),solve(s,start,end-1));
    }
}

int main(){
    string s;
    cin >> s;
    int n = s.length();
    memset(dp,-1,sizeof(dp));
    cout << solve(s,0,n-1) << endl;

}