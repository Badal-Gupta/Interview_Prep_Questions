class Solution {
public:
    void f(int n,int i,vector<int>&arr,vector<vector<int>>&b,vector<int>&a){
        if(i==n){
            b.push_back(a);
            return;
        }
        a.push_back(arr[i]);
        f(n,i+1,arr,b,a);
        a.pop_back();
        while(i+1<n&&arr[i]==arr[i+1]){
            ++i;
        }
        f(n,i+1,arr,b,a);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        int n =arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>result;
        vector<int>a;
        f(n,0,arr,result,a);
        return result;
    }
};