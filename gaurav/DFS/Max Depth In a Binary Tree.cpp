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

    int depth(TreeNode * root){

        if(!root)
            return 0;

        if(!root->left && !root->right )
            return 1;
        else 
        if(!root->left)
            return depth(root->right) + 1;
        else 
        if(!root->right)
            return depth(root->left) + 1;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};