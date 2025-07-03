class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int right = 0;
        int left = 0;
        string a ="";
        int count = 0;
        while(right<n){
            if(s[right]=='('){
                count = count+1;
            }else{
                count = count -1;
            }
            if(count !=0){
                right++;
            }else{
                a += s.substr(left+1 , right -left-1);
                left = right+1;
                right = left;
            }
        }
        return a;
    }
};