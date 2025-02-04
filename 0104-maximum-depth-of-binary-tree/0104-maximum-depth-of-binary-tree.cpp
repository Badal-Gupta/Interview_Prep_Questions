class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);

        return 1+ max(l,r);

    }
    int maxDepth(TreeNode* root) {
        int a = height(root);
        return a;
    }
};