class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int mid = 0;
            int low = 0;
        for(int nums : arr2){
            
            while(mid<n){
                if(arr1[mid]==nums){
                    swap(arr1[mid],arr1[low]);
                    low++;
                    mid++;       
                }else{
                    mid++;
                }
            }
            mid = low;
        }
        sort(arr1.begin()+low,arr1.end());
        return arr1;
    }
};