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
};\


*******************************************************  ANOTHER PROCESS ****************************************************************
class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        if(root == NULL) return {0,0};
         pair<int,int> lp = solve(root->left);
         pair<int,int>rp = solve(root->right);
         int op1 = lp.first ;
         int op2 = rp.first ;
         int op3 = lp.second + rp.second + 1;
         
         int p1 = max(op1,max(op2,op3));
         
         int p2 = max(lp.second,rp.second)+1;
         return {p1,p2};
    }


    int diameterOfBinaryTree(TreeNode* root) {
      pair<int,int> p = solve(root);
      return p.first-1 ;
    }

};
