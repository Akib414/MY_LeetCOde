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
    void solve(TreeNode* root , TreeNode* &prev){
        if(root == NULL) return ;
        TreeNode* temp = root->right ;
        if(prev != NULL)
        prev->right = root ;
        prev = root ;
        solve(root->left , prev);
         solve(temp , prev);
        root->left = NULL ;
    }

    void flatten(TreeNode* root) {
        TreeNode* prev = NULL ;
        solve(root , prev);
    }
};