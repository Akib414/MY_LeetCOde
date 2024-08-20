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