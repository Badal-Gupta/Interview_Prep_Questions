class Solution {
public:
    bool checkPerfectNumber(int num) {
        int count=0;
        for(int i=1;i<(num/2+1);i++){
            if(num%i==0){
                count+=i;
            }
        }
        if(count==num)return true;
        else return false;
    }
};