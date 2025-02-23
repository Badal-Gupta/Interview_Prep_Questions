class Solution {
public:
    bool check(int i, vector<int>&vis,vector<vector<int>>&graph){
        queue<int>q;
        q.push(i);
        vis[i]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(vis[it]==-1){
                    if(vis[node]==0){
                        vis[it]=1;
                        q.push(it);
                    }else{
                        vis[it]=0;
                        q.push(it);
                    }
                }else{
                    if(vis[node]==vis[it]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(check(i,vis,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};