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
        int p = min(a->val , b->val);
        int q = max(a->val , b->val);
        while(1){
            if( p < root->val &&  q< root->val)
            root = root->left ;
            if(p > root->val && q > root->val)
            root = root->right ;
            if(p <= root->val && q >= root->val)
            break ;
        }
        return root ;
    }
};