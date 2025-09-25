class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        dp[0][0]=arr[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==j){
                    dp[i][j]=arr[i][j]+dp[i-1][j-1];
                }else if(j==0){
                    dp[i][j]=arr[i][j]+dp[i-1][j];
                }else{
                    dp[i][j]=arr[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                
            }
        }
        long long mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(dp[n-1][i]<mini){
                mini=dp[n-1][i];
            }
        }
        return mini;
    }
};