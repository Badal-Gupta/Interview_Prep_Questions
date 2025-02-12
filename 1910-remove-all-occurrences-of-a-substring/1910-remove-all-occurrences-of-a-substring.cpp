class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        while(s.find(part) != string::npos){ 
            int a = s.find(part);
            s.erase(s.begin()+a, s.begin()+a+n);
        }
        return s;
    }
};