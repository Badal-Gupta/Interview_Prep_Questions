class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>indegree(n);
        vector<vector<int>>adj(n);
        for(auto i : p){
            indegree[i[0]]++;
        }

        for(auto i:p){
            adj[i[1]].push_back(i[0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int  count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        return count==n;
    }
};