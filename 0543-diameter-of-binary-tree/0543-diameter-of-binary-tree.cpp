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
     int solve(TreeNode* root , int &ans){
        if(root == NULL) return 0 ;
        int lft = solve(root->left , ans);
        int rgt = solve(root->right , ans);
        ans = max(lft+rgt,ans);
        return max(lft,rgt)+1;
     }

  
    int diameterOfBinaryTree(TreeNode* root) {
          int ans = 0 ;
          int height = solve(root , ans);
          return ans;    

    }
};