class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        int low = 1 ;
        int ans = -1;
        int high = *max_element(nums.begin(),nums.end());

        while(low<=high){
            int mid = (low+high)/2;
            int busquet = 0;
            int count = 0;
            for(int i:nums){
                if(i<=mid){
                    count++;
                    if(count==k){
                        busquet++;
                        count=0;
                    }
                }else{
                    count =0;
                }
            }
            if(busquet>=m){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};