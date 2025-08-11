class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // Unvisited node
                color[i] = 0;
                q.push(i);
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int nei : graph[node]) {
                        if (color[nei] == -1) {
                            color[nei] = 1 - color[node]; // Alternate color
                            q.push(nei); // Push neighbor's index
                        } else if (color[nei] == color[node]) {
                            return false; // Conflict → Not bipartite
                        }
                    }
                }
            }
        }
        return true;
    }
};
