class Solution {
public:
    void f(int i, int n, vector<int>&a , vector<int>&nums , int &sum){
        if(i>=n){
            if(!a.empty()){
            int b = a[0];
            for(int j=1;j<a.size();j++){
                b = b^a[j];
            }
            sum = sum + b;}
            return;
        }
        // if(i>=n){
        //     return;
        // }
        a.push_back(nums[i]);
        f(i+1,n,a,nums,sum);
        a.pop_back();
        f(i+1,n,a,nums,sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int>a;
        f(0,n,a,nums,sum);
        return sum;
    }
};