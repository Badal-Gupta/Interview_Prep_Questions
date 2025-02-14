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
        if(!root->left){
            return 1+find(root->right);
        }
        if(!root->right){
            return 1+find(root->left);
        }
        
        return 1+min(find(root->left),find(root->right));
    }
    int minDepth(TreeNode* root) {
        int height = find(root);
        return height;
    }
};