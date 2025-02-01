class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        double sum = 0;
        for(int i = 0;i<k;i++){
            sum=sum+arr[i];
        }
        double result = sum;
        for(int i =k;i<arr.size();i++){
            sum+=arr[i];
            sum-=arr[i-k];
            result = max(result,sum);
        }

        return result/k;
    }
};