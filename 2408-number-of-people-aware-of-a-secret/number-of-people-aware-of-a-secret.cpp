class Solution {
public:
    const int mod = 1e9+7; 
    int peopleAwareOfSecret(int n, int d, int f) {
        vector<int>dp(n+1);
        dp[1]=1;
        int count = 0;
        for(int i = 2; i<=n ;i++){
            if(i-d>=1){
                count = (count + dp[i-d])% mod;
            }
            if(i-f>=1){
                count = (count - dp[i-f] + mod)% mod;
            }

            dp[i] = count;
        }

        int people = 0;
        for(int i = n-f+1 ; i<=n;i++){
            people = (people + dp[i]) % mod;
        }

        return people;


    }
};
