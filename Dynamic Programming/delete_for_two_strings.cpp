#include<bits/stdc++.h>
using namespace std;

// LeetCode #583- Delete operations for two strings!

int MinOperations_DP(string a, string b){

    int alen = a.length();
    int blen = b.length();
    int dp[alen+1][blen+1]={0};

    //Base Case!
    dp[0][0] = 0;
    for(int i=1;i<=alen;i++) dp[i][0] = dp[i-1][0]+1;
    for(int i=1;i<=blen;i++) dp[0][i] = dp[0][i-1]+1;

    for(int i=1;i<=alen;i++){
        for(int j=1;j<=blen;j++){
            if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    return dp[alen][blen];   
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << MinOperations_DP(a,b)<<endl;

}