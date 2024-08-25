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
     
      void traverse (TreeNode* root , vector<int>&inorder ){
        if(root == NULL) return ;
        traverse(root->left , inorder);
        inorder.push_back(root->val);
        traverse(root->right , inorder);
      }

      TreeNode* make(vector<int>&inorder , int s , int e){
        if(s > e) return NULL ;
        //find mid 
        int m = s+(e-s)/2 ;
        //make a node
        TreeNode* balanced = new TreeNode(inorder[m]);
        //left part 
        balanced->left = make(inorder , s , m-1);
        //right part 
        balanced->right = make(inorder , m+1 , e);
        return balanced ;
      }

    TreeNode* balanceBST(TreeNode* root) {
        //store into vector in inorder format ;
        vector<int>inorder;
        traverse(root,inorder);
        //process
        TreeNode* balanced = make(inorder , 0 , inorder.size()-1);
        return balanced ;
        
    }
};