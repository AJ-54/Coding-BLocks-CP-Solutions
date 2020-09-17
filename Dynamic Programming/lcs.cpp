#include<bits/stdc++.h>
using namespace std;

int dp[10002][10002];
int lcs_DP(string a, string b){
    int alen = a.length();
    int blen = b.length();

    //Base Case
    for (int i=0;i<=alen;i++) dp[i][0] = 0; // considering string a at column,filling the empty index.
    for (int j=0;j<=blen;j++) dp[0][j] = 0; // considering string b at row, filling empty indexes.

    //dp[i][j] will store length of largest increasing subseq upto index i in a and j in b.
    for(int i=1;i<=blen;i++){
        for(int j=1;j<=alen;j++){
            if(a[j-1]==b[i-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[blen][alen];
}


int main(){
    string a,b;
    cin >> a >> b;
    cout << lcs_DP(a,b) << endl;
}