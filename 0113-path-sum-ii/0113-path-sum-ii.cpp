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
    void find(TreeNode* root ,int sum, int target,vector<vector<int>>&result,vector<int>&a){
        if(root==NULL){
            return;
        }
        sum = sum + root->val;
        a.push_back(root->val);
        if(isleaf(root)&&sum==target){
            result.push_back(a);
        }
        find(root->left,sum,target,result,a);
        find(root->right,sum,target,result,a);
        a.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>a;
        find(root,0,targetSum,result,a);
        return result;
    }
};