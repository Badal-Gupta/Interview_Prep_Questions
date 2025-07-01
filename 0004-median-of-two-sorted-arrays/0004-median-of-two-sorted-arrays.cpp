class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int>result;
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }else{
                result.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            result.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            result.push_back(nums2[j]);
            j++;
        }
        if((n+m)%2==1){
            return double(result[(n+m)/2]);
        }else{
            double a = result[(n+m)/2];
            cout<<a<<endl;
            double b = result[((n+m)/2)-1];
            cout<<b<<endl;
            return double((a+b)/2);        
        }
    }
};