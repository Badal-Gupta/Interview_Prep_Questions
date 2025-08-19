class Solution {
public:
    bool check(int i,int j,vector<int>&nums){
        int  a = nums[i+1] - nums[i];
        for(int k = i+1;k<=j;k++){
            if((nums[k] - nums[k-1]) !=a){
                return false;
            }
        }
        return true;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        
        int i = 0, j = 2;
        bool b = false;
        int maxi = 0;

        while(i < n && j < n){
            bool a = check(i, j, nums);
            if(a){
                b = true;
                j++;
            } else {
                if(b){
                    int d = j - i;
                    maxi += ((d*(d+1))/2) - 2*d + 1;
                    i = j-2;
                }else{
                    i++;
                    j = i+2;
                }
                b = false;
            }
        }


        if(b){
            int d = j - i;
            maxi += ((d*(d+1))/2) - 2*d + 1;
        }

        return maxi;
    }
};
