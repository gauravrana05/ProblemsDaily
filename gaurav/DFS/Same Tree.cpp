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
    bool isSame(TreeNode * p , TreeNode * q){
        
        if(!p && !q){
            return true;
        }
        else    
        if(!p || !q){
            return false;
        }

        bool left = isSame(p->left, q->left);
        bool right = isSame(p->right, q->right);

        return left && right &&(p->val == q->val);

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p, q);        
    }
};