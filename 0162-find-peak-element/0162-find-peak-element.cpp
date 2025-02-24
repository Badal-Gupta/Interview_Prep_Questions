class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int result=0;
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]<nums[mid+1]){
                result=mid+1;
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return result;
    }
};