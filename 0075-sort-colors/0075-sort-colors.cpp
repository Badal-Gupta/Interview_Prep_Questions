class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        int n= nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int i=0;
        while(mp[0]--){
            nums[i++]=0;
        }
        while(mp[1]--){
            nums[i++]=1;
        }
        while(mp[2]--){
            nums[i++]=2;
        }
        

    }
};