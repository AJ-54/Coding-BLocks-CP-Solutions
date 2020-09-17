#include<iostream>
#include<cstring>
using namespace std;

// Sanket Webinar Question
// Adjacent Bit Count - GNYR09F - SPOJ

int dp[105][105][2];

int adjBitCount(int n, int k, int first){

    //Base Case for recursive solution
    if (n==0) return 0;
    if (n==1) {
        if (k==0) return 1;
        else return 0;
    }

    // If solution is present in dp;
    if (dp[n][k][first] != -1) return dp[n][k][first];

    //If not then compute it and store it!
    
    int retval = -1;
    if (first == 1){
        retval = adjBitCount(n-1,k-1,1) + adjBitCount(n-1,k,0);
    }
    else {
        retval = adjBitCount(n-1,k,1) + adjBitCount(n-1,k,0);
    }

    return dp[n][k][first] = retval;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int num, n, k;
        cin >> num >> n >> k;
        memset(dp,-1,sizeof(dp));
        int x = adjBitCount(n,k,1);
        x += adjBitCount (n,k,0);
        cout << num << " "<< x << "\n";

    }
}