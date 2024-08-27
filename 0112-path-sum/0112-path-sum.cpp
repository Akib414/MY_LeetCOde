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
    void solve(TreeNode* root, int targetsum , int sum , bool &ans){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL){
            sum+=root->val ;
            if(sum == targetsum) ans = true ;
            return ;
        }
        if(root->left) solve(root->left , targetsum , sum+root->val , ans);
        if(root->right) solve(root->right , targetsum , sum+root->val , ans);
    }

    bool hasPathSum(TreeNode* root, int targetsum) {
        bool ans = false ;
        solve (root , targetsum , 0 , ans);
        return ans ;
    }
};