class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n<3){
            return false;
        }
        for (auto& x : word) {
            x = tolower(x);
        }
        int vowel =0;
        int consonant = 0;
        for(char a:word){
            if(!isalnum(a)){
                return false;
            }else{
                if(isalpha(a)){
                if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
                    vowel++;
                }else{
                    consonant++;
                }
                }
            }
        }
        if(vowel<1 || consonant <1){
            return false;
        }
        return true;
    }
};