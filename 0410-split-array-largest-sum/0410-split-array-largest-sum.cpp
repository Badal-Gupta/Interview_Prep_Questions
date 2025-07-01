class Solution {
public:
    int helper(vector<int>&nums , int mid , int n){
        int count = 1;
        int split = 0;
        for(int i = 0;i<n;i++){
            if(split + nums[i] <=mid){
                split+=nums[i];
            }else{
                count++;
                split = nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = low + ((high-low)/2);
            if(helper(nums,mid,n)<=k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};