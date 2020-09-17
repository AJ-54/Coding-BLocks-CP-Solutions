#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int EditDistance(char inp[100], char out[100]){
    int dp[101][101] = {};

    int m = strlen(inp);
    int n = strlen(out);

    dp[0][0] = 0;

    //Base Case 
    for(int i=1;i<=n;i++) dp[0][i] = dp[0][i-1] + 1; // This is insertion step.
    for(int i=1; i<=m;i++) dp[i][0] = dp[i-1][0] + 1; //  This is deletion step.

    //dp[i][j] denotes the number of steps required to convert input string upto i to output string upto j.
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (inp[i-1] == out[j-1]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            int q1 = dp[i-1][j-1]; // Replacement
            int q2 = dp[i-1][j]; // deletion
            int q3 = dp[i][j-1]; // Insertion
            dp[i][j] = min(q1,min(q2,q3)) + 1;
        }
    }

    return dp[m][n];
}

int main(){
    char inp[100],out[100];
    cin >> inp >> out;
    int ans = EditDistance(inp,out);
    cout << ans << endl;
}