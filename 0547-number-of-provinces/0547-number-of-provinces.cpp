class Solution {
public:
    void dfs(int start , vector<vector<int>>&adj, vector<int>&vis){
        vis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj1) {
        int n = adj1.size();
        vector<int>vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0; j<n ;j++){
                if(adj1[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i , adj , vis);
                count++;
            }
        }
        return count;
    }
};