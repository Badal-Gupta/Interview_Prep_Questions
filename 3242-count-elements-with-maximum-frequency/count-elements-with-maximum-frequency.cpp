class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int maxfre = 0;
        for(auto[num,frequency]:mp){
            maxfre =max(maxfre,frequency);
        }

        int fre =0;
        for(auto[num,frequency]:mp){
            if(maxfre == frequency){
                fre++;
            }
        }

        return fre*maxfre;

    }
};