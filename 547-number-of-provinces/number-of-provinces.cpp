class Solution {
public:
    void dfs(int i, vector<vector<int>>&adj , vector<bool>&vis){
        vis[i] = true;
        for(auto j: adj[i]){
            if(!vis[j]){
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};