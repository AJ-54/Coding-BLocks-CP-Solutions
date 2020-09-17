#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int m,n,p;

int dp[1030][1030];

int compute_paths_DP(){
    
    //Base Case
    if (dp[1][1]==0) return 0;
    dp[1][1] = 1;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1 && j==1) continue;
            if(dp[i][j]==0) continue;
            dp[i][j] = (((i-1>0)?dp[i-1][j]:0) + ((j-1>0)?dp[i][j-1]:0))%MOD;
        }
    }

    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (dp[m][n] == -1) return 0;
    return dp[m][n];

}


int main(){
    memset(dp,-1,sizeof(dp));
    cin >> m >> n >> p;
    for(int i=0;i<p;i++){
        int x,y;
        cin >> x >> y;
        dp[x][y] = 0;
    }
    cout << compute_paths_DP() <<endl;
}