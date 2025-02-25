class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            int a = target - arr[i];
            if(mp.count(a) && mp[a]!=i){
                result.push_back(i);
                result.push_back(mp[a]);
                break;
            }
        }
        return result;
    }
};