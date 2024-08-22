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
   
    void solve(int row,TreeNode* root ,  vector<int>&ans ,   map<int,bool>&m  )  {
        if(root == NULL) return ;
        if(m.find(row) == m.end()){
            m[row] =true ;
        ans.push_back(root->val);
        }
        if(root->right) solve(row+1,root->right , ans,m);
        if(root->left) solve(row+1,root->left , ans,m);
    } 

    vector<int> rightSideView(TreeNode* root ) {
       vector<int>ans ;  
       map<int,bool>m ;
       if(root == NULL) return ans ;
       solve(0,root,ans,m);
       return ans;
    }
};