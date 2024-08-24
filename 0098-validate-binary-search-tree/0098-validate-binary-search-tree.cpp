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
    bool solve(TreeNode* root ,long long int mini ,long long  int maxi){
        if(root == NULL) return true ;
        if(root->val > mini && root->val < maxi){
            return solve(root->left , mini , root->val ) && solve(root->right , root->val , maxi);
        }
        return false ;
    }

    bool isValidBST(TreeNode* root) {
        long long  int maxi = 1000000000000 ;
        long long int mini =  -1000000000000;
        return solve(root ,mini  , maxi);
    }
};