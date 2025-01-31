class Solution {
public:
    bool ispalindrome(int i,int j,string s){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void f(int n,int i,string &s,vector<string>&a,vector<vector<string>>&result){
        if(i==n){
            result.push_back(a);
            return;
        }
        for(int j = i;j<n;++j){
            if(ispalindrome(i,j,s)){
                a.push_back(s.substr(i,j-i+1));
                f(n,j+1,s,a,result);
                a.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        int n = s.length();
        vector<string>a;
        f(n,0,s,a,result);
        return result;
    }
};