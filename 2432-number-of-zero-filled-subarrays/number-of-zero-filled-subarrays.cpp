class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        long long  maxi = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }else{
                maxi += (count*(count+1))/2;
                count = 0;
            }
        }
        if(count>0){
            maxi += count*(count+1)/2;
        }
        return maxi;

    }
};