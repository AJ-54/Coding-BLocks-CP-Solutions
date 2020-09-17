#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,k;
int dp[2005][2005][10];
ll arr1[2005],arr2[2005];

int lcs_memoization(int i, int j, int k){
    
    //Base Case
    if (i==n || j==m) return 0;

    //if solution exists in dp, use it
    if (dp[i][j][k] != -1) return dp[i][j][k];
    
    if(arr1[i]!=arr2[j]){
        //I can change the value or I may not.
        //suppose I change it!

        //Assigning q1 to zero was so imp because if k would be zero, it would take random values!!
        int q1=0,q2=0,q3=0;
        if(k) q1 = lcs_memoization(i+1,j+1,k-1) + 1;
        //Suppose I dont wanna change it!
        q2 = lcs_memoization(i+1,j,k);
        q3 = lcs_memoization(i,j+1,k);
        return dp[i][j][k] = max(q1,max(q2,q3));
    }
    //There is no need to change if they are equal!
    return dp[i][j][k] = lcs_memoization(i+1,j+1,k)+1;
}

int lcs_DP(){
    
    //Lates handle the base cases first!
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (i==0||j==0){
                dp[i][j][0] = 0;
                continue;
            }
            if (arr1[i]==arr2[j]) dp[i][j][0] = 1 + dp[i-1][j-1][0];
            else dp[i][j][0] = max(dp[i-1][j][0],dp[i][j-1][0]);
            
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int p=1;p<=k;p++){
                if (i==0||j==0){
                    dp[i][j][p] = 0;
                    continue;
                }
                if (arr1[i]==arr2[j]) dp[i][j][p] = 1 + dp[i-1][j-1][p];
                else {
                    dp[i][j][p] = max(1+dp[i-1][j-1][p-1],max(dp[i-1][j][p],dp[i][j-1][p]));
                }
            }
        }
    }
    return dp[n-1][m-1][k];
}



int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> arr1[i];
    for(int i=0;i<m;i++) cin >> arr2[i];
    int ans = lcs_memoization(0,0,k);
     memset(dp,-1,sizeof(dp));
    // int ans2 = lcs_DP();
    cout << ans << endl;
    // cout << ans2 << endl;
}