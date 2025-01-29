class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int left =0;
        int right = n-1;
        int area = 0;
        while(left<right){
            int plotarea=0;
            if(arr[left]>arr[right]){
                plotarea = arr[right]*(right-left);
                right--;
            }else{
                plotarea = arr[left]*(right-left);
                left++;
            }
            area = max(area,plotarea);
        }
        return area;
    }
};