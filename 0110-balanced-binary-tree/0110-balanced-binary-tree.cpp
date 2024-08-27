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
// class Solution {
// public:

//     int solve(TreeNode* root , bool &ans){
//         if(root == NULL) return 0 ;
//         int lft = solve(root->left , ans);
//         int rgt = solve(root->right , ans);
//         if(abs(lft - rgt) > 1) ans = false ;
//         return max(lft, rgt)+1;
//     }

//     bool isBalanced(TreeNode* root) {
//         bool ans = true ;
//         int height = solve(root , ans);
//         return ans ;
//     }
// };



//another process 


class Solution {
public:
   pair<int,bool> solve(TreeNode* root){
    if(root == NULL) return  {0,true};
     pair<int,bool>l = solve(root->left);
     pair<int,bool>r = solve(root->right);
     pair<int,bool>ans ;
     ans.first = max(l.first,r.first)+1;
     if(abs(l.first - r.first) <= 1 && l.second && r.second) ans.second = true ;
     else ans.second = false ;
     return ans;
   
   }


    bool isBalanced(TreeNode* root) {
        pair<int,bool> p = solve(root);
        return p.second;
    }
};
