/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh;
        if(root->left){
            lh = find(root->left);
        }
        else{
            return 1+find(root->right);
        }
        int rh;
        if(root->right)
            rh = find(root->right);
        else{
            return 1+find(root->left);
        }

        return 1+min(lh,rh);
    }
    int minDepth(TreeNode* root) {
        int height = find(root);
        return height;
    }
};