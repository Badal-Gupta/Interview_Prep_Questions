class Solution {
public:
    int isVowel(char ch){
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    bool doesAliceWin(string s) {
        // int count=0;
        // for(int i=0;i<s.size();i++){
        //     if(isVowel(s[i])){
        //         count++;
        //     }
        // }
        // if(count>0){
        //     return true;
        // }else{
        //     return false;
        // }

        for(auto i: s){
            if(isVowel(i)){
                return true;
            }
        }
        return false;
    }
};