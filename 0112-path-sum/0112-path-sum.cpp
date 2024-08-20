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
     void solve(TreeNode* root , bool &flag , int &sum,int targetSum){
        if(root->left == NULL && root->right == NULL){
            sum+=root->val;
            if(sum == targetSum) flag = true ;
            sum-=root->val ;
             return ;
        }
        
        if(root->left != NULL){
        sum+=root->val ;    
        solve(root->left,flag , sum , targetSum) ;
         sum-=root->val;
  
        }
        if(root->right != NULL){
            sum+=root->val ; 
        solve(root->right,flag , sum , targetSum);
       sum-=root->val;
        }
    
               
        
     }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false ;
        bool flag = false ;
        int sum = 0 ;
        solve(root , flag , sum , targetSum);
         return flag ;
    }
};