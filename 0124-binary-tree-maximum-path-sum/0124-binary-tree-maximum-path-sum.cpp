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
    int check(TreeNode* root , int &maxi){
        if(root==NULL){
            return 0;
        }
        int lsum = max(0,check(root->left,maxi));
        int rsum = max(0,check(root->right,maxi));

        maxi = max(maxi,(lsum+rsum+root->val)); // left side + right side (root ki value)
        return root->val + max(lsum,rsum);   // har iteration pe sum return karna hai path ka idherleft 
                                            //ither right jo bada ho wo 
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        check(root,maxi);
        return maxi;
    }
};