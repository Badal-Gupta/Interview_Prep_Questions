class Solution {
public:
    void f(int n,int i,vector<int>&arr,set<vector<int>>&result,vector<int>&a,int sum,int target){
        if(sum>target)return;
        if(sum==target){
            result.insert(a);
            return;
        }
        if(i==n)return;

        sum+=arr[i];
        a.push_back(arr[i]);
        f(n,i+1,arr,result,a,sum,target);
        sum-=arr[i];
        a.pop_back();
        for(int j=i;j<n-1;j++){
            if(arr[i]==arr[j+1]){
                i++;
            }
        }
        f(n,i+1,arr,result,a,sum,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        int n=arr.size();
        set<vector<int>>result;
        vector<vector<int>>result1;
        vector<int>a;
        sort(arr.begin(),arr.end());
        f(n,0,arr,result,a,0,target);
        for(auto i:result){
            result1.push_back(i);
        }
        return result1;
    }
};