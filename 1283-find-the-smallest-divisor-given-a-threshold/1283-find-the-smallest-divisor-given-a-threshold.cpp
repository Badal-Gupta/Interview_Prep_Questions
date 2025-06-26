class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            int total = 0;
            for(int i: nums){
                total = total + (i+mid-1)/mid;
            }
            if(total<=t){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};