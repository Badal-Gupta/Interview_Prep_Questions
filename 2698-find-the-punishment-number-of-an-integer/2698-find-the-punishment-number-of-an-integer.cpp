class Solution {
public:
    bool check(int sq , int target , int currentSum){
        if(sq==0){
            return target == currentSum;
        }
        int mil = 1, part = 0;
        while(sq>0){
            part = (sq%10)*mil + part;
            sq= sq/10;
            mil = mil*10;
            if(check(sq,target,currentSum+part))return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int sq = i*i;
            if(check(sq,i,0)){
                sum = sum + sq;
            }
        }
        return sum;
    }
};