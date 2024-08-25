/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(root == NULL) return root ;
        while(root != NULL){
        if(a->val > root->val && b->val > root->val)
        root = root->right ; 
        else if(a->val < root->val && b->val < root->val)
        root = root -> left ;
        else
        break ;
        }
        return root ;
    }
};