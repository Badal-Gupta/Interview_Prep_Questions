// User function Template for C++

class Solution {
  public:
    bool helper(vector<int>&arr,int dist, int k,int n){
        int count = 1;
        int low = arr[0];
        for(int i = 1;i<n;i++){
            if((arr[i]-low) >= dist){
                count++;
                low = arr[i];
            }
            if(count>=k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high = stalls[n-1];
        while(low<=high){
            int mid = low + (high-low)/2;
            if(helper(stalls,mid,k,n)){
                low = mid+1;
            }else{
                high = mid-1;
            }
            
        }
        return high;
    }
};