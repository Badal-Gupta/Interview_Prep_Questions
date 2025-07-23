class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 0;
        vector<int>arr;
        for(auto i: nums){
            if(arr.empty() || arr.back() < i){
                arr.push_back(i);
                len++;
            }else{
                auto a = lower_bound(arr.begin(),arr.end(),i);
                arr[a-arr.begin()] = i;
            }
        }
        return len;
    }
};