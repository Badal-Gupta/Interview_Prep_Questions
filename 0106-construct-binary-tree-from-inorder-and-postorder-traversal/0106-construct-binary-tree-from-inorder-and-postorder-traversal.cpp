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
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int>mp;
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        TreeNode* root = build(post,post.size()-1,0,in,0,in.size()-1,mp);
        return root;    
    }
    TreeNode* build(vector<int>&post,int postend ,int poststart ,vector<int>&in ,int instart,int inend,unordered_map<int,int>&mp){
        if(instart>inend||postend<poststart){
            return NULL;
        }

        TreeNode* root = new TreeNode(post[postend]);
        int pos = mp[root->val];
        int right = inend - pos;

        root->left = build(post,postend-right-1,poststart,in,instart,pos-1,mp);
        root->right = build(post,postend-1,postend-right,in,pos+1,inend,mp);
        return root;
    }
};