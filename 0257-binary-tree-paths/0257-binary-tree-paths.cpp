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
    bool isleaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->left!=NULL||root->right!=NULL){
            return false;
        }
        return true;
    }
    void find(TreeNode* root, string a, vector<string>&result){
        if(isleaf(root)){
            a+=to_string(root->val);
            result.push_back(a);
            return;
        }
        a+= to_string(root->val);
        a+= "->";
        if(root->left)find(root->left,a,result);
        if(root->right)find(root->right,a,result);
        a.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(root==NULL){
            return result;
        }
        string a="";
        find(root,a,result); 
        return result;
    }
};