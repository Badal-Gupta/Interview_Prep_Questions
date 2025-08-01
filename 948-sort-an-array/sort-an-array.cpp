class Solution {
public:

    void merge(vector<int>&arr,int low , int mid, int high){
        int i = low;
        int j = mid+1;
        vector<int>result;
        while(i<=mid && j<=high){
            if(arr[i]>arr[j]){
                result.push_back(arr[j]);
                j++;
            }else{
                result.push_back(arr[i]);
                i++;
            }
        }
        while(i<=mid){
            result.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            result.push_back(arr[j]);
            j++;
        }
        for(int k = 0;k<result.size();k++){
            arr[low+k] = result[k];
        }
    }
    void mergesort(vector<int>&arr,int low,int high){
        if(low>=high){
            return;
        }
        int mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n= nums.size()-1;
        mergesort(nums,0,n);
        return nums;
    }
};