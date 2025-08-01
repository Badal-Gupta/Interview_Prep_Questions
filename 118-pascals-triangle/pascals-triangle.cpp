class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp;
        dp.push_back({1});
        for(int i =1;i<n;i++){
            vector<int>a;
            a.push_back(1);
            for(int j = 1;j<i;j++){
                a.push_back(dp[i-1][j-1]+dp[i-1][j]);
            }
            a.push_back(1);
            dp.push_back(a);
        }
        return dp;
    }
};