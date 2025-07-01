// User function template for C++

class Solution {
  public:
    int helper(vector<int>&arr,int mid , int n){
        int count = 1;
        int painted = 0;
        for(int i =0;i<n;i++){
            if(painted + arr[i] <= mid){
                painted+= arr[i];
            }
            else{
                count++;
                painted = arr[i];
            }
        }
        return count;
    }
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            if(helper(arr,mid,n)<=k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};