class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*, TreeNode*> mp;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        }
        int dist = 0;
        unordered_map<TreeNode*, int> visited;
        visited[target]++;
        q.push(target);
        while (!q.empty()) {
            if (dist < k) {
                int s = q.size();
                for (int i = 0; i < s; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) {
                        if (!visited.count(node->left)) {
                            q.push(node->left);
                            visited[node->left]++;
                        }
                    }
                    if (node->right) {
                        if (!visited.count(node->right)) {
                            q.push(node->right);
                            visited[node->right]++;
                        }
                    }
                    if (mp[node]) {
                        if (!visited.count(mp[node])) {
                            q.push(mp[node]);
                            visited[mp[node]]++;
                        }
                    }
                }
                dist++;
            }else{
                break;
            }
        }
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};