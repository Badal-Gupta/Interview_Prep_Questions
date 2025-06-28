class Solution {
public:
    int shipWithinDays(vector<int>& nums, int d) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int count = 0;
            int i = 0;
            while (i < n) {
                long long cost = 0;
                while (i < n && cost + nums[i] <= mid) {
                    cost += nums[i];
                    i++;
                }
                count++;
            }
            if (count <= d) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};