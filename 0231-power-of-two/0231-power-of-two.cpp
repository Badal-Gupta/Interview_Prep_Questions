class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }else if(n%2==1){
            return false;
        }
        while(n>=2){
            if(n==2){
                return true;
            }
            n=n>>1;
        }
        return false;
    }
};