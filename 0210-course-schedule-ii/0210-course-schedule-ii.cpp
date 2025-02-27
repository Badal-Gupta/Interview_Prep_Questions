class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st,vector<int>&pathvis){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(it,vis,adj,st,pathvis)){
                    return true;
                }
            }else if(pathvis[it]==1){
                return true;
            }
        }
        pathvis[i]=0;
        st.push(i);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        for(auto i:p){
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>result;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,st,pathvis)){
                    return result;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};