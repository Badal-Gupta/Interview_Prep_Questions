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
    void sum(TreeNode* root, string a, long long &result){
        if(root==NULL){
            return;
        }
        a.push_back(root->val+'0');
        if(isleaf(root)){
            result = result + stoll(a);
        }
        sum(root->left,a,result);
        sum(root->right,a,result);
        a.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        long long result=0;
        sum(root,"",result);
        return result;
    }
};