class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int target = accumulate(arr.begin(),arr.end(),0);
         if(target%3!=0){
            return false;
        }
        target = target/3;
       
        int count =0;
        for(int i = 0;i<n;i++){
            sum = sum + arr[i];
            if(sum==target){
                count++;
                sum=0;
            }
            if(count==2 && i<n-1)return true;
        }
        return false;
    }
};