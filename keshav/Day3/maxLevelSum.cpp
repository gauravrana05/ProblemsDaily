class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        int ans = 1;
        int maxSum = root->val;
        int curSum = 0;
        int curlevel = 2;
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
        TreeNode* t = new TreeNode(INT_MAX);
        q.push(t);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp == t){
                if(curSum > maxSum){
                    ans = curlevel;
                    maxSum = curSum;
                }
                curlevel++;
                curSum = 0;
                if(!q.empty()) q.push(t);
            }
            else{
                curSum+= temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};
Console
