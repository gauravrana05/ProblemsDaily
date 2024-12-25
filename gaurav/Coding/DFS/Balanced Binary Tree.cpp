
class Solution {
public:

    pair<bool, int> isBal(TreeNode * root){

        if(!root) 
            return {true, 0};
        else
        if(!root->left &&!root->right){
            return {true, 1};
        }
        else
        if(!root->left){

            pair<bool, int> p = isBal(root->right);

            if( p.second > 1 || !p.first){
                return {false, p.second + 1};
            }
            else{
                return {true, p.second + 1};
            }


        }
        else
        if(!root->right){

            pair<bool, int> p = isBal(root->left);

            if( p.second > 1 || !p.first){
                return {false, p.second + 1};
            }
            else{
                return {true, 2};
            }

        }

        pair<bool, int> left = isBal(root->left);
        
        pair<bool, int> right = isBal(root->right);

        if(abs(right.second - left.second) > 1 || !left.first || !right.first){
            return {false, max(right.second,left.second) + 1};
        }
        else
            return {true,  max(right.second, left.second) + 1};


    }

    bool isBalanced(TreeNode* root) {
        return isBal(root).first;
    }
};