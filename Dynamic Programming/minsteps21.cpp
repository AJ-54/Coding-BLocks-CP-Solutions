#include<iostream>
#include<bits/stdc++.h>
#include<cstring>

using namespace std;
// This is a spj problem where dp approach takes linear time and it gives TLE!!!!
//Problem is MST1 - Minimum Steps to one - I think its a graph based problem - BFS for them!!
int computegreedy(int n){
    // This is is a greedy approach wherein I am trying for locally optimal solution and this is wrong
    int b1=0,b2=0,b3=0;
    while (n>1){
        if (n%3==0) n=n/3,b3++;
        else if (n%2==0) n=n/2,b2++;
        else n=n-1,b1++;
    }
    return b1+b2+b3;
}

int top_down(int* dp, int n){
    //Base Case
    if (n==1) return 0;
    
    //If solution is present in dp
    if (dp[n] != 0) {
        return dp[n];
    }
    //else compute solution and store it in dp.
    int ans = computedp(dp,n-1) + 1;
    if (n%3==0) {
        return dp[n] = min(ans,computedp(dp,n/3) + 1);
    }
    if (n%2==0){
        return dp[n] = min(ans,computedp(dp,n/2) + 1);
    }
    return dp[n] = ans;
}

int bottom_up(int n){
    int *dp = new int[n+1]();
    dp[1] = 0;
    for (int i=2;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        if (i%3 == 0) dp[i] = min(dp[i],dp[i/3] + 1);
        if (i%2 == 0) dp[i] = min(dp[i],dp[i/2] + 1);
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        //For top_down :
        // int *dp = new int[n+1]();
        // memset(dp,0,sizeof(dp));
        cout << "Case " << i+1 << ": "<< bottom_up(n)  << endl;
    }
}