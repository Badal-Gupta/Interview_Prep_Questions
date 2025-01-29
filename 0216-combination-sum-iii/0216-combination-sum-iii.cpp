class Solution {
public:
    void f(int n,int i ,int target, vector<int>&arr,vector<vector<int>>&result,vector<int>&a,int k,int sum,int element){
        if(element==k && sum==target){
            result.push_back(a);
            return;
        }
        if (i==n)return;
        sum+=arr[i];
        a.push_back(arr[i]);
        f(n,i+1,target,arr,result,a,k,sum,element+1);
        sum-=arr[i];
        a.pop_back();
        f(n,i+1,target,arr,result,a,k,sum,element);
    } 
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        int n = 9;
        vector<vector<int>>result;
        vector<int>a;
        f(n,0,target,arr,result,a,k,0,0);
        return result;                        
    }
};