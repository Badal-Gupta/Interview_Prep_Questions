class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int h=n-1;
        int mid=0;
        while(mid<=h){
            if(nums[mid]%2==0){
                swap(nums[l],nums[mid]);
                l++;
                mid++;
            }else{
                swap(nums[h],nums[mid]);
                h--;
            }
        }
        return nums;

    }
};