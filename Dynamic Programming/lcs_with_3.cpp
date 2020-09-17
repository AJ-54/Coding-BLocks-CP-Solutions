#include<bits/stdc++.h>
using namespace std;

int dp[300][300][300];
int lcs_DP(string a, string b, string c){
    int alen = a.length();
    int blen = b.length();
    int clen = c.length();
   

    //dp[i][j] will store length of largest increasing subseq upto index i in a and j in b.
    for(int i=0;i<=alen;i++){
        for(int j=0;j<=blen;j++){
            for(int k=0;k<=clen;k++){
            if (i==0||j==0||k==0) {
                dp[i][j][k] = 0;
                continue;
                }
    
            if((a[i-1]==b[j-1])&&(b[j-1]==c[k-1])) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
            else  dp[i][j][k] = max( dp[i][j-1][k],
            max(dp[i-1][j][k],dp[i][j][k-1]));
            
            }
        }
    }
    return dp[alen][blen][clen];
}


int main(){
    string a,b,c;
    cin >> a >> b >> c;
    cout << lcs_DP(a,b,c) << endl;
}