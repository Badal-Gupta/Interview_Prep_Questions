class Solution {
public:
    void f(int n,int i,vector<int>&arr,vector<int>&a,vector<vector<int>>&result,int target,int sum){
            if(sum>target)return;
            if(sum==target){
                result.push_back(a);
                return;
            }
            if(i==n) return ;
        sum=sum+arr[i];
        a.push_back(arr[i]);
        f(n,i,arr,a,result,target,sum);
        sum-=arr[i];
        a.pop_back();
        f(n,i+1,arr,a,result,target,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>result;
        vector<int>a;
        f(n,0,arr,a,result,target,0);
        return result;
    }
};