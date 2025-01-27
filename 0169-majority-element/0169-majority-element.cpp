class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int a;
        for(auto i:mp){
            if(i.second>n/2){
             a = i.first;
            }
        }
        return a;
    }
};