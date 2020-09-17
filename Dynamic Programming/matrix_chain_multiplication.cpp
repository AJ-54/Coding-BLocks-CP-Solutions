#include<bits/stdc++.h>
using namespace std;

int arr[1005];
int dp[1000][1000];

// Recursive code into Top-Down DP code!
int MatrixChain(int i, int j){

    //Base Case
    if (i==j) return 0;

    //If solution already in DP!
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for (int k=i;k<j;k++){
        int temp = MatrixChain(i,k) + MatrixChain(k+1,j) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans,temp);
    }

    return dp[i][j]=ans;
}

//We can build bottom-up similar way!

int main(){
    int n;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << MatrixChain(1,n-1);
}