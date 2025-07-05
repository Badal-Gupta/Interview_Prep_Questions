class Solution {
public:
    int myAtoi(string s) {
        int flag = 1;
        int i =0;
        long long result=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(s[i] == '+'|| s[i]=='-'){
            if(s[i]=='-'){
                flag = -flag;
            }
            i++;
        }

        while(i<s.size() && isdigit(s[i])){
            result = (result*10) +(s[i]-'0');
            if(result > INT_MAX){
                if(flag == 1){
                    return INT_MAX;
                }else{
                    return INT_MIN;
                }
            }
            i++;
        }
        return result*flag;
    }
};