class Solution {
public:
    bool find(TreeNode* root, TreeNode* target,vector<TreeNode*>&a){
        if(root==NULL){
            return false;
        }
        a.push_back(root);
        if(root==target){
            return true;
        }
        
        if (find(root->left, target, a) || find(root->right, target, a))
            return true;
        a.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a;
        vector<TreeNode*>b;
        find(root,p,a);
        find(root,q,b);
        int x = a.size();
        int y = b.size();
        int different=-1;
        if(x>=y){
            for(int i=0;i<y;i++){
                if(a[i]==b[i]){
                    different=i;
                }
            }
            if(different!=-1)return b[different];
            else return root;
        }else{
            for(int i=0;i<x;i++){
                if(a[i]==b[i]){
                    different=i;
                }
            }
            if(different!=-1)return a[different];
            else return root;
        }
        
    
    }
};