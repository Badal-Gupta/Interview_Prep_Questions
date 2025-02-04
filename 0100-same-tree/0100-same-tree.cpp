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
    bool issame(TreeNode* p , TreeNode* q){
        if(p==NULL||q==NULL){
            return (p==q);
        }
        return (p->val==q->val)&&issame(p->left,q->left)&&issame(p->right,q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool a = issame(p,q);
        return a; 
    }
};