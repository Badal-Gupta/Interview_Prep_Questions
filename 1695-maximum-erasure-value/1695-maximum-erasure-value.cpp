class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int sum = 0, result = 0;
        int i = 0, j = 0;

        while (j < n) {
            if (!st.count(nums[j])) {
                st.insert(nums[j]);
                sum += nums[j];
                result = max(result, sum);
                j++;
            } else {
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
        }
        return result;
    }
};
