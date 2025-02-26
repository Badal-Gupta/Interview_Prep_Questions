class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<vector<int>>&graph,vector<int>&pathvis){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:graph[i]){
            if(!vis[it]){
                if(dfs(it,vis,graph,pathvis)){
                    return true;
                }
            }else if(pathvis[it]==1){
                return true;
            }
        }
        pathvis[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> graph(numCourses);  
        for(auto i : p){
            graph[i[1]].push_back(i[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,graph,pathvis)){
                    return false;
                }
            }
        }
        return true;

    }
};