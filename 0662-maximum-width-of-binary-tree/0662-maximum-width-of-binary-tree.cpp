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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        unsigned int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int s = q.size();
            int minn = q.front().second;
            unsigned last , first;
            for(int i = 0;i<s;i++){
                TreeNode* node = q.front().first;
                unsigned index = q.front().second-minn;
                q.pop();
                if(i==0) first = index;
                if(i==s-1) last = index;
                if(node->left){
                    q.push({node->left,(index*2)+1});
                }
                if(node->right){
                    q.push({node->right,(index*2)+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};