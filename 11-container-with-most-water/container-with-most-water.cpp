class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int area =0;
        int maxi =0;
        while(right>left){
            if(arr[left]>arr[right]){
                area = arr[right]  * (right - left);
                right--;
            }else{
                area = arr[left] * (right - left);
                left++;
            }
            maxi = max(maxi,area);
        }
        return maxi;
    }
};