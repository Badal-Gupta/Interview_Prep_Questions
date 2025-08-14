class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string triple = num.substr(i, 3);
                if (ans == "" || triple > ans) {
                    ans = triple;
                }
            }
        }
        return ans;
    }
};
