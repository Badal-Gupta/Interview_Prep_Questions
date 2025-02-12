class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int,int>mp;
        for(int i =0;i<in.size();i++){
            mp[in[i]]=i;
        }
        TreeNode* root = build(pre,0,pre.size()-1,in,0,in.size()-1,mp);
        return root;
    }
    TreeNode* build(vector<int>&pre, int prestart , int preend, vector<int>&in, int instart , int inend,map<int,int>&mp){
        if(prestart>preend || instart>inend){
            return NULL;
        }

        TreeNode* root = new TreeNode(pre[prestart]);

        int rootpos = mp[root->val];
        int left = rootpos-instart;
        root->left=build(pre,prestart+1,prestart+left,in,instart,rootpos-1,mp);
        root->right = build(pre,prestart+left+1,preend,in,rootpos+1,inend,mp);
        return root;

    }
};