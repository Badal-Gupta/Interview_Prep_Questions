class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=INT_MIN;
        int product =1;
        for(int i=0;i<nums.size();i++){
            product = product*nums[i];
            if(product>max){
                max=product;
            }
            if(product==0){
                product=1;
            }
        }
        return max;
    }
};