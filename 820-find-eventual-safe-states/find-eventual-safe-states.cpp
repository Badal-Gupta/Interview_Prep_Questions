class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(auto j :graph[i]){
                indegree[i]++;
            }
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto j :graph[i]){
                adj[j].push_back(i);
            }
        }
        queue<int>q;
        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto i: adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};