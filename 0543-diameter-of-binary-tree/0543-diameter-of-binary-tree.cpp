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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0 ;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return max(l,r)+1;
    }
    int solve(TreeNode* root){
             if(root == NULL) return 0 ;
     int op1 = solve(root->left);
     int op2 = solve(root->right);
     int op3 = maxDepth(root->left) + maxDepth(root->right) + 1;

     return max(op1,max(op2,op3));
    } 


      
    int diameterOfBinaryTree(TreeNode* root) {
      return solve(root)-1;
    }

};