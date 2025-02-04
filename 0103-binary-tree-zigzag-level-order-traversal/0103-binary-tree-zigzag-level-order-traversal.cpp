class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool a = true;
        while(!q.empty()){
            int n = q.size();
            vector<int>level(n);

            for(int i = 0 ;i<n;i++){
                TreeNode* node = q.front();
                q.pop();

                int index = (a) ? i : (n-1-i);
                level[index]= node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            a=!a;
            result.push_back(level);
        }
        return result;
    }
};