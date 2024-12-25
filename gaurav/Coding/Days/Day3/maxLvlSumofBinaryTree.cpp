#include<iostream>
#include<vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * */
  struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int depth(TreeNode* root){
        if(root == NULL )
            return 0;
            return 1 + max(depth(root->left), depth(root->right));
    }
    void solve(TreeNode * root, int level, vector<int> &lvlSum){
        if( root == NULL ) 
            return;
        lvlSum[level] += root->val;
        solve(root->left, level + 1, lvlSum);
        solve(root->right, level + 1, lvlSum);

    }

    int maxLevelSum(TreeNode* root) {
        int d = depth(root);
        vector<int> lvlSum(d, 0);

        solve(root, 0, lvlSum);
        int mx = INT_MIN, ans ;
        int it = 1;
        for( auto i: lvlSum){
            cout<<i<<" ";
            if(mx < i){
                mx = i;
                ans = it;
            }
            it++;
        }
        return ans;

    }
};