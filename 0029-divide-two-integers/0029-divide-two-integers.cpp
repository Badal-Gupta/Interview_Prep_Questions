class Solution {
public:
    int divide(int d, int d2) {
        long long result;
        if(d== INT_MIN && d2==-1){
            return INT_MAX;
        }
        result = floor(d/d2);
        return result;
    }
};