class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int  n = s1.size();
        int m = s2.size();

        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
         int i = n ; 
         int j = m ; 
         string a = "";
         while(i>0 && j>0){
            if(s1[i]==s2[j]){
                a.push_back(s1[i-1]);
                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                a.push_back(s1[i-1]);
                i--;
            }else{
                a.push_back(s2[j-1]);
                j--;
            }
         }

         while(i>0){
            a.push_back(s1[i-1]);
            i--;
         }
         while(j>0){
            a.push_back(s2[j-1]);
            j--;
         }

         reverse(a.begin(),a.end());
         return a;
    }
};