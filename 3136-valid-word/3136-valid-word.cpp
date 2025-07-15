class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if (n < 3) {
            return false;
        }
        for (auto& x : word) {
            x = tolower(x);
        }
        bool vowel = false;
        bool consonant = false;
        for (char a : word) {
            if (!isalnum(a)) {
                return false;
            } else {
                if (isalpha(a)) {
                    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' ||
                        a == 'u') {
                        vowel=true;
                    } else {
                        consonant=true;
                    }
                }
            }
        }
        if (vowel && consonant) {
            return true;
        }
        return false;
    }
};