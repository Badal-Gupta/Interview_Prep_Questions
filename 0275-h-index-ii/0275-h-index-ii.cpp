class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        int high = n;
        int low = 0;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            auto it = lower_bound(arr.begin(), arr.end(), mid);
            int cnt = arr.end() - it;
            if(cnt>=mid){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};