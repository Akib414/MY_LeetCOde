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
    void traverse_in(TreeNode* root , vector<int>&inorder){
        if(root == NULL) return ;
        traverse_in(root->left , inorder);
        inorder.push_back(root->val);
        traverse_in(root->right , inorder);
    }

     TreeNode* create(vector<int>&inorder , int st , int end){
        if(st > end || st < 0 || end >=inorder.size()) return NULL ;
        int mid = st+(end-st)/2 ;
        TreeNode* balanced = new TreeNode(inorder[mid]);
        balanced->left = create(inorder , st , mid-1);
        balanced->right = create(inorder , mid+1 , end);
        return balanced ;
     }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
         traverse_in(root , inorder);
        TreeNode* balanced = create(inorder , 0 , inorder.size()-1);
        return balanced ;
    }
};