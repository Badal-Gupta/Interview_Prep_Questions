class Solution {
public:
    void f(string s, int i , string a, vector<string>&result,string mapping[]){
        if(i>=s.length()){
            result.push_back(a);
            return;
        }
        int d = s[i] - '0';
        string val = mapping[d];
        for(int j=0 ; j<val.length() ; j++){
            a.push_back(val[j]);
            f(s,i+1,a,result,mapping);
            a.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        vector<string>result;
        if(s.length()==0){
            return result;
        }
        string a;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(s,0,a,result,mapping);
        return result;
    }
};