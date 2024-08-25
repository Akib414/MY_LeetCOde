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

    TreeNode* solve(vector<int>& preorder , int & i , int low , int high){
        //when i reaches its limit 
        if(i >= preorder.size()) return NULL;
        //if it is not between the limit then it is not possible for it place here 
        if(preorder[i]<low || preorder[i]> high ) return NULL ;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = solve(preorder , i , low , root->val);
        root->right = solve(preorder , i , root->val , high);
        return root ;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0 ;
        //at first the limits infinity
        TreeNode * ans = solve(preorder , i , INT_MIN , INT_MAX);
        return ans ;

    }
};