class Solution {
public:
    const int mod=1e9+7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<int> dp(n+1);
        dp[1]=1;
        int total=0;

        for(int i=2;i<=n;i++){
            if(i-delay>=1)total=(total+dp[i-delay])%mod;
            if(i-forget>=1)total=(total-dp[i-forget]+mod)%mod;

            dp[i]=total;
        }

        int ans=0;
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};