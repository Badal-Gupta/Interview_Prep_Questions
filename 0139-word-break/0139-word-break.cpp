class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        int m = wordDict.size();
        vector<int>vis(m,0);
        // while(s.length()>0 && m>0){
            for(int i = 0;i<wordDict.size();i++){
                int a = s.find(wordDict[i]);
                if(a>=0 && a<n){
                    int b=wordDict[i].length();
                    s.erase(s.begin()+a , s.begin()+a+b);
                    vis[i]=1;
                }else{
                    return false;
                }
            }
        // }
        for(int i=0; i<wordDict.size(); i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};
