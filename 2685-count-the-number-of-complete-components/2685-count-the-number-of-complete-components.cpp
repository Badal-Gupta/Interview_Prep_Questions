class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int result = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                int count_node = 0;
                int count_edge = 0;
                vis[i]=1;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    count_node++;
                    for (auto it : adj[node]) {
                        count_edge++;
                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
                if (((count_node) * (count_node - 1) / 2) == count_edge/2) {
                    result++;
                }
            }
        }
        return result;
    }
};