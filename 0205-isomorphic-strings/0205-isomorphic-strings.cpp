class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char>mp;
        unordered_map<char,int>mp2;
        for(int i =0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }else{
                if(mp2[t[i]]!=1){
                    mp[s[i]]=t[i];
                    mp2[t[i]] = 1;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};