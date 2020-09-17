class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int *dp = new int[n]();
        // This is a top-down approach
        for (int i=2;i<n;i++){
            if (A[i] - A[i-1] == A[i-1] - A[i-2]){
                dp[i] = dp[i-1] + 1;
            }
        }
        return accumulate(dp,dp+n,0);
    }
};