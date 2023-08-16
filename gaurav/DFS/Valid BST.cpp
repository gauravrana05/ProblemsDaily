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

    pair<int, int> isBST(TreeNode* root, bool &ans){

        if(root->left == NULL && root->right == NULL){
            return {root->val, root->val};
        }
    
        pair<int, int> left, right;
    
    if(root->left && root->right){
        left = isBST(root->left, ans);
        right = isBST(root->right, ans);
        if(left.second >= root->val || right.first <= root->val )   
            ans = false;
        return {left.first, right.second};
        }
    else
    if(root->left){
        
        left = isBST(root->left, ans);
        if(left.second >= root->val)
            ans = false;
        
        return {left.first,root->val};
        }
    else
        {
        
        right = isBST(root->right, ans);
        if(right.first <= root->val)
            ans = false;
        
        return {root->val, right.second};
        }
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
         
        isBST(root, ans);

        return ans;
    }
};