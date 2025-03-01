// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
        
//         int n = s.length();
//         int m = wordDict.size();
//         vector<int>vis(m,0);
//         // while(s.length()>0 && m>0){
//             for(int i = 0;i<wordDict.size();i++){
//                 int a = s.find(wordDict[i]);
//                 if(a>=0 && a<n){
//                     int b=wordDict[i].length();
//                     s.erase(s.begin()+a , s.begin()+a+b);
//                     vis[i]=1;
//                 }else{
//                     return false;
//                 }
//             }
//         // }
//         for(int i=0; i<wordDict.size(); i++){
//             if(vis[i]==0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto i : wordDict){
            st.insert(i);
        }
        vector<int>dp(s.length()+1,0);
        dp[0]=1;
        for(int i =0;i<=s.length();i++){
            for(int j = 0;j<i;j++){
                string a = s.substr(j,i-j);
                if(dp[j]&&st.find(a)!=st.end()){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};