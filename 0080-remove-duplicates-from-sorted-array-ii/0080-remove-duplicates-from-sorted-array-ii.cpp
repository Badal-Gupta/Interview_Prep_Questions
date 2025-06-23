class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        int j = 1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1] && count<2){
                nums[j]=nums[i];
                j++;
                count++;
            }else if(nums[i]!=nums[i-1]){
                count=0;
                nums[j]=nums[i];
                count++;
                j++;
            }
        }
        return j;
    }
};