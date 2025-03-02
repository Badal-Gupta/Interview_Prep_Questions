class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        for(auto i : nums1){
            mp[i[0]]=i[1];
        }
        for(auto i: nums2){
            mp[i[0]] += i[1];
        }
        // int m = mp.size();
        vector<vector<int>>result;
        for(auto i : mp){
            vector<int>a(2);
            a[0]=i.first;
            a[1]=i.second;
            result.push_back(a);
        }
        return result;
    }
};