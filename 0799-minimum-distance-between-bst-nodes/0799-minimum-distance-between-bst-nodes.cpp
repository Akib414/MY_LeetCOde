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
   int maxleft(TreeNode* root){
    if(root->right == NULL) return root->val ;
    return maxleft(root->right);
   }

   int minright (TreeNode* root){
    if(root->left == NULL) return root->val ;
    return minright(root->left);
   }


    void solve(TreeNode* root , int &mini){
        if(root == NULL) return  ;
        solve(root->left,mini);
        solve(root->right,mini);
        if(root->left) {
            int maximum_in_left = maxleft(root->left);
            mini= min(mini , abs(root->val - maximum_in_left));
        }
        if(root->right){
        int minimum_in_right = minright(root->right);
        mini = min(mini , abs(root->val - minimum_in_right));
        }
    }


    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX ;
       solve(root , mini);
        return mini ;
    }
};