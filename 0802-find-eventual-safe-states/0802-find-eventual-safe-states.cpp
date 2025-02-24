class Solution {
public:
    bool dfs(int i, vector<vector<int>>&graph, vector<int>&vis , vector<int>&pathvis , vector<int>&check){
        vis[i]=1;
        pathvis[i]=1;

        for(auto it: graph[i]){
            if(!vis[it]){
                if(dfs(it,graph,vis,pathvis,check)==true){
                    check[it]=0;
                    return true;
                }
            }else if(pathvis[it]){
                check[it]=0;
                return true;
            }
        }
        check[i]=1;
        pathvis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(graph.size(),0);
        vector<int>pathvis(graph.size(),0);
        vector<int>check(graph.size(),0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,check);
            }
        }
        vector<int>result;
        for(int i = 0;i<n;i++){
            if(check[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};