class Solution {
public:
    int isVowel(char ch){
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    string sortVowels(string s) {
        vector<int>index;
        vector<int>ascii;
        for(int i =0;i<s.size();i++){
            if(isVowel(s[i])){
                ascii.push_back(static_cast<int>(s[i]));
                index.push_back(i);
            }
        }
        sort(ascii.begin(),ascii.end());
        for(int i =0;i<ascii.size();i++){
            s[index[i]] = static_cast<char>(ascii[i]);
        }
        return s;
    }
};