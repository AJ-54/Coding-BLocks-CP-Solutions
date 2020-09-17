#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arr[1000005];
int dp[1000050];

int longest_inc_subseq(int n){
    
    //Base Case
    for (int i=1;i<=n;i++) dp[i] = 1;

    //dp[i] denotes count of subseq's ending at i.
    //It is not necessary that longest subseq ends at last index only. 
    int best = -1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if (arr[i]>=arr[j]) dp[i] = max(dp[i],dp[j]+1);
        }
        best = max(best,dp[i]);
    }
    // for(int i=1;i<=n;i++) cout << dp[i] << " ";cout<<endl;
    return best;
}

int main(){
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin>>arr[i];
    int ans = longest_inc_subseq(n);
    cout << ans << endl;
}