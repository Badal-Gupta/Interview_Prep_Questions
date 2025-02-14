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

    bool check(TreeNode* root ,int sum,int  target){
        if(root==NULL){
            return false;
        }
        sum = sum + root->val;
        if(isleaf(root)){
            if(sum==target){
                return true;
            }
        }
        return check(root->left,sum,target)||check(root->right,sum,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,0,targetSum);
    }
};