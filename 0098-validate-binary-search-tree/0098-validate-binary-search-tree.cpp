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
    bool solve(TreeNode* root , long int low ,long int high){
        if(root == NULL) return true ;
        bool lft = solve(root->left , low , root->val) ;
        bool rgt = solve(root->right , root->val , high);
         if(root->val > low && root->val < high && lft && rgt) return true ;
         return false ;
    }


    bool isValidBST(TreeNode* root) {
        long int maxi = 9999999999;
        long int mini = -9999999999;
        return solve(root , mini , maxi);
    }
};