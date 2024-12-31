class Solution {
public:

    bool isSym(TreeNode * p , TreeNode * q){
        
        if(!p && !q){
            return true;
        }
        else    
        if(!p || !q){
            return false;
        }

        bool left = isSym(p->left, q->right);
        bool right = isSym(p->right, q->left);

        return left && right &&(p->val == q->val);

    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return isSym(root->left, root->right);

    }
};