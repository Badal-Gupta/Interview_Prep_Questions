class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        vector<int>b;
        for(int i =0;i<n;i++){
            if(nums[i]>=0){
                a.push_back(nums[i]);
            }else{
                b.push_back(nums[i]);
            }
        }
        int  j =0;
        for(int i = 0 ;i<n ;i=i+2){
            nums[i]=a[j++];
        }
        a.clear();
        j=0;
        for(int i=1;i<n;i=i+2){
            nums[i]=b[j++];
        }
        b.clear();
        return nums;


    }
};