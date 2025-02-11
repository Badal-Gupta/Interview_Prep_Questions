class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>arr(2,-1);
        int n = nums.size();
        if(n==0){
            return arr;
        }

        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                arr[0]=mid;
                high = mid-1;
            }
            if(nums[mid]>target){
                high=mid-1;
            }
            if(nums[mid]<target){
                low=mid+1;
            }
        }
        low = 0;
        high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                arr[1]=mid;
                low=mid+1;
            }
            if(nums[mid]>target){
                high=mid-1;
            }
            if(nums[mid]<target){
                low=mid+1;
            }
        }
        return arr;
    }
};