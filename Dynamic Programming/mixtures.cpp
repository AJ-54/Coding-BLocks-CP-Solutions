    #include<bits/stdc++.h>
    using namespace std;

    int arr[500];
    int dp[500][500];
    int  n;

    int minsmoke_DP(){
        int csum[n+1];
        for(int i=0;i<n;i++) dp[i][i] = 0,csum[i] = (i>0)?csum[i-1]+arr[i]:arr[0];
        for(int len=2;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j = i+len-1;
                dp[i][j] = INT_MAX;
                for(int k=i;k<j;k++){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+
                    ((csum[k]-((i>0)?csum[i-1]:0))%100)*((csum[j]-csum[k])%100));
                }
            }
        }
        return dp[0][n-1];
    }

    int main(){

        
        while(scanf("%d",&n)!=EOF){

            memset(dp,0,sizeof(dp));
            //Read n integers
            for(int i=0;i<n;i++) cin >> arr[i];
            cout << minsmoke_DP() << endl;
            memset(arr,0,sizeof(arr));
            
        }
        
    }