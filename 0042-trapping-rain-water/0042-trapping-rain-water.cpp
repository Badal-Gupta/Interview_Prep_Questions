class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left_max = arr[0];
        int right_max = arr[n-1];
        int left = 0;
        int right = n-1;
        int area = 0;
        while(left<=right){
            if(left_max<right_max){
                left_max = max(left_max, arr[left]);
                area = area + (left_max -arr[left]); 
                left++; 
            }else{
                right_max = max(right_max , arr[right]);
                area = area + (right_max - arr[right]);
                right--;
            }
        }
        return area;

    }
};