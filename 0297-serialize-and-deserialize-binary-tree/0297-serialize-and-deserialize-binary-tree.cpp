class Codec {
public:
    string serialize(TreeNode* root) {
        string a = "";
        if(root==NULL){
            return a;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL){
                a.append("#,");
            }else{
                a.append(to_string(node->val)+",");
            }
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return a;
    }

    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }else{
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }else{
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
            
        }
        return root;
    }
};