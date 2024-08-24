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
        
    void solve(TreeNode* root , TreeNode* &ans , int val){
        if(root == NULL || root->val == val){
         ans = root ;   
         return ;
        } 
        if(root->val > val) solve(root->left , ans , val);
        if(root->val < val) solve(root->right, ans , val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans ;
        solve(root ,ans , val);
        return ans;
    }
};