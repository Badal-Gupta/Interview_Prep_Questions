// class Solution {
// public:

//     bool check(vector<int>&a){
//         int n=a.size();
//         for(int i=2;i<n;i++){
//             if(a[i]!=a[i-1]+a[i-2]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     void generate(int i ,int n, vector<int>&a , vector<int>&arr,int &maxi){
//         if(a.size()>=3){
//             if(check(a)){
//                 maxi = max(maxi,(int)a.size());
//             }
//         }
//         if(i==n){
//             return;
//         }
//         a.push_back(arr[i]);
//         generate(i+1,n,a,arr,maxi);
//         a.pop_back();
//         generate(i+1,n,a,arr,maxi);
//     }
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n=arr.size();
//         vector<int>a;
//         int maxi =0;
//         generate(0,n,a,arr,maxi);
//         return maxi;
//     }
// };
class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n=arr.size();
            unordered_map<int,int>mp;
            vector<vector<int>>dp(n,vector<int>(n,0));
            for(int i=0;i<n;i++){
                mp[arr[i]]=i;
            }
            int maxi=0;

            for(int i=0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    int target = arr[i]+arr[j];
                    if(mp.count(target)){
                        int k = mp[target];
                        dp[j][k]= dp[i][j]>0?dp[i][j]+1:3;
                        maxi = max(maxi,dp[j][k]); 
                    }
                }
            }
            return maxi;
        }
};