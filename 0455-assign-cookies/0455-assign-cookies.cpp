class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = g.size()-1;
        int i = s.size()-1;
        while(j>=0 && i>=0){
            if(g[j]<=s[i]){
                result++;
                j--;
                i--;
            }else if(g[j]>s[i]){
                j--;
            }
        }
        return result;
    }
};