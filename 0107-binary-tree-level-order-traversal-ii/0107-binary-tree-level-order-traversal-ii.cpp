class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>a;
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                a.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            result.insert(result.begin(),a);
        }
        return result;
    }
};